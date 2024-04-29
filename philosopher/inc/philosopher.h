/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2024/04/29 02:47:21 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>
# include "../Libft/libft.h"

typedef struct s_philo
{
	int					id;
	long int			last_eat;
	pthread_mutex_t		eat;
	struct timeval		time;
	pthread_t			thread;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		*r_fork;
	struct s_watcher			*watcher;
}			t_philo;

typedef struct s_watcher
{
	int		n_philo;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		n_eat;
	pthread_mutex_t		print;
	pthread_mutex_t		access;
	struct timeval	start_time;
	t_philo	*philos;
}			t_watcher;


int		is_num(char c);

void	FREE_philo(t_watcher *watcher);
void	*LIFE(void *data);
int		PHILOSOPHERS(t_watcher *watcher);

#endif
