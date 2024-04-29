/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:50 by eboumaza          #+#    #+#             */
/*   Updated: 2024/04/29 23:12:42 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	END_Threads(t_philo *philo)
{
	int	i;
	
	i = 0;
	pthread_mutex_lock(&philo->watcher->access);
	while (i < philo->watcher->n_philo)
	{
		(void)philo->watcher->philos[i];
		i++;
	}
	pthread_exit(NULL);
}

void	TAKE_Fork(t_philo *philo)
{	
	//gettimeofday(&philo->time, NULL);
	//if (philo->last_eat + philo->watcher->die_time < philo->time.tv_usec)
	//	END_Threads(philo);
	//philo->last_eat = philo->time.tv_usec;
	pthread_mutex_lock(philo->r_fork);
	PRINT_Philo(philo, " has taken a fork");
	pthread_mutex_lock(&philo->l_fork);
	PRINT_Philo(philo, " has taken a fork");
}

void	EAT(t_philo *philo)
{
	PRINT_Philo(philo, " is eating");
	pthread_mutex_lock(&philo->eat);
	gettimeofday(&philo->time, NULL);
	philo->last_eat = philo->time.tv_usec;
	pthread_mutex_unlock(&philo->eat);
	WAIT(philo->watcher->eat_time, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}


void	SLEEP(t_philo *philo)
{
	PRINT_Philo(philo, " is sleeping");
	WAIT(philo->watcher->sleep_time, philo);
}

void	*LIFE(void *data)
{
	t_philo	*philo;
	int		i;
	//pthread_mutex_t	mutex;

	philo = ((t_philo *)data);
	i = 0;
	if (philo->id % 2 == 0)
		usleep(100);
	//printf("Philo %d intialise\n", philo->id);
	if (philo->id == 1 && gettimeofday(&philo->watcher->start_time, NULL))
		exit(0);
	while (philo->id && (philo->watcher->n_eat == 0 || philo->watcher->n_eat > i))
	{
		TAKE_Fork(philo);
		EAT(philo);
		SLEEP(philo);
		i++;
	}
	//pthread_mutex_init(&mutex, NULL);
	//usleep(300);
	//pthread_mutex_unlock(&mutex);
	END_Threads(philo);
	pthread_exit(NULL);
	return (NULL);
}
int	PHILOSOPHERS(t_watcher *watcher)
{
	(void)watcher;
	return (1);
}

