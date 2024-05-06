/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:50 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/06 13:44:02 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_philo(philo, " has taken a fork");
	pthread_mutex_lock(&philo->l_fork);
	print_philo(philo, " has taken a fork");
}

void	eat_sleep(t_philo *philo)
{
	print_philo(philo, " is eating");
	pthread_mutex_lock(&philo->eat);
	philo->n_meal++;
	philo->last_eat = get_time_philo();
	pthread_mutex_unlock(&philo->eat);
	wait(philo->watcher->eat_time);
	print_philo(philo, " is sleeping");
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	wait(philo->watcher->sleep_time);
}

void	*life(void *data)
{
	t_philo	*philo;
	int		i;

	philo = ((t_philo *)data);
	i = 0;
	pthread_mutex_lock(&philo->eat);
	wait_start_philo(philo);
	pthread_mutex_unlock(&philo->eat);
	if (philo->id % 2 == 0)
		usleep(100);
	while (is_alive(philo, i))
	{
		take_fork(philo);
		eat_sleep(philo);
		i++;
	}
	return (NULL);
}
