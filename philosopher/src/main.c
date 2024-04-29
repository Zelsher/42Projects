/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:22:01 by eboumaza          #+#    #+#             */
/*   Updated: 2024/04/29 22:58:49 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

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

void	FILL_Watcher(int argc, char **argv, t_watcher *watcher)
{
	pthread_mutex_init(&watcher->print, NULL);
	if (argc < 5 || argc > 6 || !verify_arg(argc, argv))
	{
		printf("Erreur d'arguments : %d\n", argc);
		exit (0);
	}
	watcher->n_philo = ft_atoi(argv[1]);
	watcher->die_time = ft_atoi(argv[2]);
	watcher->eat_time = ft_atoi(argv[3]);
	watcher->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		watcher->n_eat = ft_atoi(argv[5]);
	if (argc == 6 && !watcher->n_eat)
		exit(0);
	watcher->n_eat = 0;
	watcher->n_time = 0;
	
	pthread_mutex_init(&(watcher->print), NULL);
	pthread_mutex_init(&(watcher->access), NULL);
	//printf("Start time : %ld\n%d Philos\n%d Temps pour mourir\n%d Temps pour manger\n%d Temps pour dormir\n", watcher->start_time.tv_usec, watcher->n_philo, watcher->die_time, watcher->eat_time, watcher->sleep_time);
}

int	CREATE_Philo(t_watcher *watcher, int i)
{
	watcher->philos[i].id = i + 1;
	watcher->philos[i].watcher = watcher;
	watcher->philos[i].r_fork = NULL;
	pthread_mutex_init(&(watcher->philos[i].l_fork), NULL);
	pthread_mutex_init(&(watcher->philos[i].eat), NULL);
	if (i == watcher->n_philo - 1)
		watcher->philos[i].r_fork = &watcher->philos[0].l_fork;
	else
		watcher->philos[i].r_fork = &watcher->philos[i + 1].l_fork;
	pthread_create(&watcher->philos[i].thread, NULL, &LIFE, &watcher->philos[i]);
	return (1);
}

int	FILL_Philos(t_watcher *watcher)
{
	int	i;

	i = 0;
	watcher->philos = malloc(sizeof(t_philo) * watcher->n_philo);
	while (i < watcher->n_philo)
	{
		CREATE_Philo(watcher, i);
		//printf("%d\n", i);
		i++;
	}
	i = 0;
	while (i < watcher->n_philo)
	{
		if (pthread_join(watcher->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_watcher	watcher;

	FILL_Watcher(argc, argv, &watcher);
	FILL_Philos(&watcher);
	if (PHILOSOPHERS(&watcher))
		return (printf("Repas finit !\n"), 0);
	return (1);
}


//./philosopher 5 800 200 200 4