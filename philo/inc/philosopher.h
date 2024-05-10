/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/10 15:31:33 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>
# include <pthread.h>

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
	int				die_time;
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
int		ft_atoi(const char *str);

void	*death(void *data);

int		is_alive(t_philo *philo, int lunch);
int		verify_arg(int argc, char **argv);
void	wait_start(t_watcher *watcher);
void	wait_start_philo(t_philo *philo);
void	print_philo(t_philo *philo, char *action);
size_t	get_time_philo(void);
void	waiter(int wait_time);
void	*life(void *data);

#endif
