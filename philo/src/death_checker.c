/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:33:30 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/06 13:44:23 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	*decimate_philos(t_watcher *watcher)
{
	pthread_mutex_lock(&watcher->access);
	watcher->dead = 1;
	pthread_mutex_unlock(&watcher->access);
	return (NULL);
}

int	is_alive(t_philo *philo, int lunch)
{
	pthread_mutex_lock(&philo->watcher->access);
	if (philo->watcher->dead
		|| (philo->watcher->n_eat != 0 && philo->watcher->n_eat == lunch))
	{
		pthread_mutex_unlock(&philo->watcher->access);
		return (0);
	}
	pthread_mutex_unlock(&philo->watcher->access);
	return (1);
}

int	finish_meal(t_watcher *watcher)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&watcher->access);
	while (i < watcher->n_philo)
	{
		pthread_mutex_lock(&watcher->philos[i].eat);
		if (!watcher->n_eat || watcher->philos[i].n_meal == watcher->n_eat)
		{
			pthread_mutex_unlock(&watcher->philos[i].eat);
			pthread_mutex_unlock(&watcher->access);
			return (0);
		}
		pthread_mutex_unlock(&watcher->philos[i].eat);
		i++;
	}
	pthread_mutex_unlock(&watcher->access);
	return (1);
}

void	*death(void *data)
{
	t_watcher	*watcher;
	int			i;

	watcher = ((t_watcher *)data);
	wait_start(watcher);
	while (1)
	{
		i = 0;
		while (i + 1 < watcher->n_philo)
		{
			if (!finish_meal(watcher))
				return (NULL);
			pthread_mutex_lock(&watcher->philos[i].eat);
			if ((int)(get_time_philo() - watcher->philos[i].last_eat)
				>= watcher->die_time)
			{
				print_philo(&watcher->philos[i], " Died");
				pthread_mutex_unlock(&watcher->philos[i].eat);
				return (decimate_philos(watcher));
			}
			pthread_mutex_unlock(&watcher->philos[i].eat);
			i++;
		}
	}
}
