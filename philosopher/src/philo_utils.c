/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:34:24 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/03 16:56:38 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	PRINT_Philo(t_philo *philo, char *action)
{
	if (philo->watcher->dead == 1)
		return ;
	pthread_mutex_lock(&philo->watcher->print);
	printf("%ld %d%s\n", GET_Time_Philo() - philo->watcher->start_time, philo->id, action);
	pthread_mutex_unlock(&philo->watcher->print);
}

size_t	GET_Time_Philo()
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday() error\n", 22);
		return (0);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);	
}

int	verify_arg(int argc, char **argv)
{
	int	i;
	int j;

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
