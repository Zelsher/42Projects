/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:34:24 by eboumaza          #+#    #+#             */
/*   Updated: 2024/04/29 23:11:30 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	PRINT_Philo(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->watcher->print);
	printf("%ld %d%s\n", GET_Time_Philo(philo), philo->id, action);
	pthread_mutex_unlock(&philo->watcher->print);
}

void	WAIT(int wait_time, t_philo *philo)
{
	int	i;

	i = 0;
	//printf("%d Attend %d ms\n", philo->id, wait_time);
	while (i < wait_time * 100)
	{
		usleep(50);
		usleep(50);
		i += 100;
	}
	(void)philo;
}

long int	GET_Time_Philo(t_philo *philo)
{
	gettimeofday(&philo->time, NULL);
	//if (philo->watcher->start_time.tv_sec + 1 == philo->time.tv_sec)
		//philo->watcher->start_time.tv_usec += 1000000;
	printf("%d : %ld |  %ld\n", philo->id, philo->watcher->start_time.tv_usec , philo->time.tv_usec);
	return (philo->time.tv_usec - philo->watcher->start_time.tv_usec);
}

int	is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);	
}

void	FREE_philo(t_watcher *watcher)
{
	(void)watcher;
}
