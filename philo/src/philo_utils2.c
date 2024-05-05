#include "../inc/philosopher.h"

void	WAIT_Start(t_watcher *watcher)
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

void	WAIT_Start_Philo(t_philo *philo)
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

void	WAIT(int wait_time)
{
	size_t	start;

	start = GET_Time_Philo();
	while ((GET_Time_Philo() - start) < (size_t)wait_time)
		usleep(500);
}
