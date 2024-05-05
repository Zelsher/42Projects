/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:31:50 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/05 21:44:21 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	TAKE_Fork(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	PRINT_Philo(philo, " has taken a fork");
	pthread_mutex_lock(&philo->l_fork);
	PRINT_Philo(philo, " has taken a fork");
}

void	EAT_SLEEP(t_philo *philo)
{
	PRINT_Philo(philo, " is eating");
	pthread_mutex_lock(&philo->eat);
	philo->n_meal++;
	philo->last_eat = GET_Time_Philo();
	pthread_mutex_unlock(&philo->eat);
	WAIT(philo->watcher->eat_time);
	PRINT_Philo(philo, " is sleeping");
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	WAIT(philo->watcher->sleep_time);
}

void	*LIFE(void *data)
{
	t_philo	*philo;
	int		i;

	philo = ((t_philo *)data);
	i = 0;
	pthread_mutex_lock(&philo->eat);
	WAIT_Start_Philo(philo);
	pthread_mutex_unlock(&philo->eat);
	if (philo->id % 2 == 0)
		usleep(100);
	while (IS_Alive(philo, i))
	{
		TAKE_Fork(philo);
		EAT_SLEEP(philo);
		i++;
	}
	//printf("%d a manger %d repas\n", philo->id, i);
	return (NULL);
}
