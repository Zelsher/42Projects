/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/03 18:50:58 by eboumaza         ###   ########.fr       */
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
	int					n_meal;
	size_t				last_eat;
	pthread_t			thread;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		lock;
	pthread_mutex_t		eat;
	struct s_watcher	*watcher;
}			t_philo;

typedef struct s_watcher
{
	int				n_philo;
	size_t			die_time;
	int				eat_time;
	int				sleep_time;
	int				n_eat;
	int				n_time;
	int				dead;
	size_t			start_time;
	pthread_t		death_thread;
	pthread_mutex_t	m_start;
	pthread_mutex_t	print;
	pthread_mutex_t	access;
	t_philo			*philos;
}			t_watcher;


int		is_num(char c);

void	*DEATH(void *data);

int		IS_Alive(t_philo *philo, int lunch);
int		verify_arg(int argc, char **argv);
void	WAIT_Start(t_watcher *watcher);
void	WAIT_Start_Philo(t_philo *philo);
void	PRINT_Philo(t_philo *philo, char *action);
size_t	GET_Time_Philo();
void	WAIT(int wait_time);
void	*LIFE(void *data);

#endif
