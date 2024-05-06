/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:34:24 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/06 13:48:00 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	print_philo(t_philo *philo, char *action)
{
	if (philo->watcher->dead == 1)
		return ;
	pthread_mutex_lock(&philo->watcher->print);
	printf("%ld %d%s\n", get_time_philo() - philo->watcher->start_time,
		philo->id, action);
	pthread_mutex_unlock(&philo->watcher->print);
}

size_t	get_time_philo(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday() error\n", 22);
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	verify_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		while (argv[j][i])
		{
			if (!is_num(argv[j][i]) || argv[j][i] == '-')
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
