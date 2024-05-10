/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:50 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/10 16:01:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_philo(philo, " has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_philo(philo, " has taken a fork");
}

void	eat_sleep(t_philo *philo)
{
	print_philo(philo, " is eating");
	pthread_mutex_lock(&philo->eat);
	philo->n_meal++;
	philo->last_eat = get_time_philo();
	pthread_mutex_unlock(&philo->eat);
	waiter(philo->watcher->eat_time);
	print_philo(philo, " is sleeping");
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	waiter(philo->watcher->sleep_time);
	print_philo(philo, " is thinking");
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
	if (philo->id % 2 == 0 || philo->id == philo->watcher->n_philo)
		usleep(1000);
	if (philo->watcher->n_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		waiter(philo->watcher->die_time);
		printf("%d 1 died\n", philo->watcher->die_time);
		return (0);
	}
	while (is_alive(philo, i))
	{
		take_fork(philo);
		eat_sleep(philo);
		i++;
	}
	return (NULL);
}
