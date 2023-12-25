/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_random_atoi(const char *str, size_t len)
{
	long long int	result;
	size_t			i;

	i = 0;
	result = 0;
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		if (i == len)
			break ;
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

static long long int	ft_seeder(char *time)
{
	int					i;
	long long int		num;

	i = 1;
	while (time[i - 1] != '.')
		i++;
	num = ft_random_atoi(time, i);
	if (time[i] != '0' || time[i + 1] != '0')
		num *= ft_power(ft_random_atoi(time + i, 2), 2);
	while (time[i] != '.')
		i++;
	if (time[i + 1] == '0' && time[i + 2] == '0')
	{
		i -= 2;
		while (time[i + 1] == 0)
			i--;
		num *= ft_power(ft_random_atoi(time + i, 2), 2);
	}
	else
		num *= ft_power(ft_random_atoi(time + i + 1, 2), 2);
	return (num);
}

static int	ft_seed_len(long long int seed)
{
	long long int	temp;
	int				moove;
	int				i;

	i = 1;
	if (seed < 0)
		seed = seed * -1;
	temp = seed;
	while (temp >= 10)
	{
		i++;
		temp /= 10;
	}
	moove = i - (ft_nbr_reducer(seed, 1));
	if (moove < 5)
		moove = 5;
	seed = (ft_nbr_reducer(seed, moove));
	while (seed > 65536)
		seed /= 10;
	return ((int)seed);
}

int	ft_random_seed(long long int seed)
{
	int		fd;
	char	*time;

	if (seed < 0)
		seed *= -1;
	if (seed == 0)
	{
		fd = open("/proc/uptime", O_RDONLY);
		if (fd == 0)
		{
			ft_printf("Erreur ft_random, verifier /proc/uptime");
			return (0);
		}
		time = get_next_line(fd);
		close(fd);
		seed = ft_seed_len(ft_seeder(time));
		free(time);
	}
	else
	{
		seed = (1664525 * seed + 1013904223) % 4294967296;
		seed = ft_seed_len(seed);
	}
	return (seed);
}

long long int	ft_random(int seed, int len, int sign)
{
	long long int	num;

	num = (1664525 * seed + 1013904223) % 4294967296;
	if (num < 0)
		num *= -1;
	num = ft_nbr_reducer(num, len);
	while (seed >= 10)
		seed /= 10;
	if (sign != 0 && seed < 5)
		num *= -1;
	return (num);
}
