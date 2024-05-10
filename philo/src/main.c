/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:22:01 by eboumaza          #+#    #+#             */
/*   Updated: 2024/05/10 15:31:06 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

void	end_philos(t_watcher *watcher)
{
	int	i;

	i = 0;
	while (i < watcher->n_philo)
	{
		pthread_mutex_destroy(&watcher->philos[i].l_fork);
		pthread_mutex_destroy(watcher->philos[i].r_fork);
		pthread_mutex_destroy(&watcher->philos[i].eat);
		i++;
	}
	free(watcher->philos);
	pthread_mutex_destroy(&watcher->access);
	pthread_mutex_destroy(&watcher->print);
	pthread_mutex_destroy(&watcher->m_start);
	return ;
}

void	fill_watcher(int argc, char **argv, t_watcher *watcher)
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
	if ((argc == 6 && !watcher->n_eat)
		|| watcher->n_philo <= 0 || watcher->die_time < 0
		|| watcher->eat_time < 0 || watcher->eat_time < 0
		|| watcher->sleep_time < 0)
	{
		printf("Erreur d'arguments : %d\n", argc);
		exit (0);
	}
	watcher->start_time = 0;
	watcher->dead = 0;
}

int	create_philo(t_watcher *watcher, int i)
{
	watcher->philos[i].id = i + 1;
	watcher->philos[i].n_meal = 0;
	watcher->philos[i].last_eat = 0;
	watcher->philos[i].watcher = watcher;
	watcher->philos[i].r_fork = NULL;
	pthread_mutex_init(&(watcher->philos[i].l_fork), NULL);
	pthread_mutex_init(&(watcher->philos[i].eat), NULL);
	if (i == watcher->n_philo - 1)
		watcher->philos[i].r_fork = &watcher->philos[0].l_fork;
	else
		watcher->philos[i].r_fork = &watcher->philos[i + 1].l_fork;
	pthread_create(&watcher->philos[i].thread, NULL, &life,
		&watcher->philos[i]);
	return (1);
}

int	fill_philos(t_watcher *watcher)
{
	int	i;

	i = 0;
	pthread_mutex_init(&watcher->print, NULL);
	pthread_mutex_init(&(watcher->access), NULL);
	pthread_mutex_init(&(watcher->m_start), NULL);
	pthread_create(&watcher->death_thread, NULL, &death, watcher);
	while (i < watcher->n_philo)
	{
		create_philo(watcher, i);
		i++;
	}
	pthread_mutex_lock(&watcher->m_start);
	watcher->start_time = get_time_philo();
	pthread_mutex_unlock(&watcher->m_start);
	if (pthread_join(watcher->death_thread, NULL))
		return (1);
	i = 0;
	while (i < watcher->n_philo)
	{
		if (pthread_join(watcher->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_watcher	watcher;

	fill_watcher(argc, argv, &watcher);
	if (watcher.n_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		waiter(watcher.die_time);
		printf("%d 1 died\n", watcher.die_time);
		return (0);
	}
	watcher.philos = malloc(sizeof(t_philo) * watcher.n_philo);
	if (!watcher.philos)
		return (0);
	if (fill_philos(&watcher))
		printf("Erreur de Thread\n");
	end_philos(&watcher);
	return (1);
}

//./philosopher 5 800 200 200 4