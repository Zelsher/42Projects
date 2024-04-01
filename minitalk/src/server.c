/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:55:42 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/07 18:55:42 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_exit(t_data *data)
{
	ft_printf("Message received : [%s]\n", data->p_str);
	data->bit = 0;
	data->i = 0;
	data->verif = 0;
	free(data->p_str);
	kill(data->c_pid, SIGUSR2);
	data->c_pid = 0;
}

void	fill_data(t_data *data, int pid)
{
	data->c_pid = pid;
	ft_printf("Client PID : %d\n", data->c_pid);
	kill(data->c_pid, SIGUSR1);
}

void	ft_malloc_str(t_data *data)
{
	data->str = malloc(sizeof(char) * data->i + 1);
	if (!data->str)
	{
		kill(data->c_pid, SIGUSR2);
		ft_printf("Malloc failed\n");
		exit(0);
	}
	data->p_str = data->str;
	data->i = 0;
	data->bit = 0;
	data->verif = 1;
}

void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	static t_data	data;

	ft_printf("OUI");
	if (!data.c_pid)
		return (fill_data(&data, info->si_pid));
	if (signum == SIGUSR2 && data.verif == 1)
		data.i |= (1 << (7 - data.bit));
	else if (signum == SIGUSR2)
		data.i |= (1 << (31 - data.bit));
	data.bit++;
	if (data.bit == 8 && data.verif == 1)
	{
		*data.str = data.i;
		data.str++;
		if (!data.i)
			return (ft_exit(&data));
		data.bit = 0;
		data.i = 0;
	}
	else if (data.bit == 32)
		ft_malloc_str(&data);
	kill(data.c_pid, SIGUSR1);
	(void)context;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_printf("Faillure\n"), 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Faillure\n"), 1);
	while (1)
		pause();
	return (1);
}
