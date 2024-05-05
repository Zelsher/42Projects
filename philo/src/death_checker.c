#include "../inc/philosopher.h"

void	*DECIMATE_Philos(t_watcher *watcher)
{
	pthread_mutex_lock(&watcher->access);
	watcher->dead = 1;
	pthread_mutex_unlock(&watcher->access);
	return (NULL);
}

int	IS_Alive(t_philo *philo, int lunch)
{
	pthread_mutex_lock(&philo->watcher->access);
	if (philo->watcher->dead || 
		(philo->watcher->n_eat != 0 && philo->watcher->n_eat == lunch))
	{
		pthread_mutex_unlock(&philo->watcher->access);
		return (0);
	}
	pthread_mutex_unlock(&philo->watcher->access);
	return (1);
}

int	FINISH_Meal(t_watcher *watcher)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&watcher->access);
	while (i < watcher->n_philo)
	{
		pthread_mutex_lock(&watcher->philos[i].eat);
		if (!watcher->n_eat || watcher->philos[i].n_meal == watcher->n_eat)
		{
			pthread_mutex_unlock(&watcher->philos[i].eat);
			pthread_mutex_unlock(&watcher->access);
			return (0);
		}
		pthread_mutex_unlock(&watcher->philos[i].eat);
		i++;
	}
	pthread_mutex_unlock(&watcher->access);
	return (1);
}

void	*DEATH(void *data)
{
	t_watcher	*watcher;
	int			i;

	watcher = ((t_watcher *)data);
	WAIT_Start(watcher);
	while (1)
	{
		i = 0;
		while (i + 1 < watcher->n_philo)
		{
			if (!FINISH_Meal(watcher))
				return (NULL);
			pthread_mutex_lock(&watcher->philos[i].eat);
			if ((int)(GET_Time_Philo() - watcher->philos[i].last_eat) >= watcher->die_time)
			{
				//printf("%ld\n", GET_Time_Philo() - watcher->philos[i].last_eat);
				PRINT_Philo(&watcher->philos[i], " Died");
				pthread_mutex_unlock(&watcher->philos[i].eat);
				return (DECIMATE_Philos(watcher));
			}
			pthread_mutex_unlock(&watcher->philos[i].eat);
			i++;
		}
	}
}
