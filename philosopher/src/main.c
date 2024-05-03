/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:22:01 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/03 19:10:23 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"


void	END_Philos(t_watcher *watcher)
{
	int	i;

	i = 0;
	while (i < watcher->n_philo)
	{
		pthread_mutex_destroy(&watcher->philos[i].l_fork);
		pthread_mutex_destroy(watcher->philos[i].r_fork);
		pthread_mutex_destroy(&watcher->philos[i].lock);
		pthread_mutex_destroy(&watcher->philos[i].eat);
		i++;
	}
	free(watcher->philos);
	pthread_mutex_destroy(&watcher->access);
	pthread_mutex_destroy(&watcher->print);
	pthread_mutex_destroy(&watcher->m_start);
	return ;
}

void	FILL_Watcher(int argc, char **argv, t_watcher *watcher)
{
	if (argc < 5 || argc > 6 || !verify_arg(argc, argv))
	{
		printf("Erreur d'arguments : %d\n", argc);
		exit (0);
	}
	watcher->n_philo = ft_atoi(argv[1]);
	watcher->die_time = ft_atoi(argv[2]);
	watcher->eat_time = ft_atoi(argv[3]);
	watcher->sleep_time = ft_atoi(argv[4]);
	watcher->n_eat = 0;
	if (argc == 6)
		watcher->n_eat = ft_atoi(argv[5]);
	//printf("Start time : %ld\n%d Philos\n%ld Temps pour mourir\n%d Temps pour manger\n%d Temps pour dormir\n", watcher->start_time, watcher->n_philo, watcher->die_time, watcher->eat_time, watcher->sleep_time);
	pthread_mutex_init(&watcher->print, NULL);
	pthread_mutex_init(&(watcher->access), NULL);
	pthread_mutex_init(&(watcher->m_start), NULL);
	watcher->start_time = 0;
	watcher->dead = 0;
	if (argc == 6 && !watcher->n_eat)
		exit(0);
}

int	CREATE_Philo(t_watcher *watcher, int i)
{
	watcher->philos[i].id = i + 1;
	watcher->philos[i].n_meal = 0;
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
	pthread_create(&watcher->death_thread, NULL, &DEATH, watcher);
	while (i < watcher->n_philo)
	{
		CREATE_Philo(watcher, i);
		i++;
	}
	watcher->start_time = GET_Time_Philo();
	i = 0;
	pthread_join(watcher->death_thread, NULL);
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
	watcher.philos = malloc(sizeof(t_philo) * watcher.n_philo);
	if (!watcher.philos)
		return (0);
	FILL_Philos(&watcher);
	END_Philos(&watcher);
	return (1);
}

//./philosopher 5 800 200 200 4