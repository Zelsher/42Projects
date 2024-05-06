/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:39:12 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/06 13:39:39 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	wait_start(t_watcher *watcher)
{
	while (1)
	{
		pthread_mutex_lock(&watcher->m_start);
		if (watcher->start_time)
		{
			pthread_mutex_unlock(&watcher->m_start);
			break ;
		}
		pthread_mutex_unlock(&watcher->m_start);
	}
}

void	wait_start_philo(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->watcher->m_start);
		if (philo->watcher->start_time)
		{
			philo->last_eat = philo->watcher->start_time;
			pthread_mutex_unlock(&philo->watcher->m_start);
			break ;
		}
		pthread_mutex_unlock(&philo->watcher->m_start);
	}
}

void	wait(int wait_time)
{
	size_t	start;

	start = get_time_philo();
	while ((get_time_philo() - start) < (size_t)wait_time)
		usleep(500);
}
