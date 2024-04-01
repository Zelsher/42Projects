/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_sides(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	while (map[y])
	{
		x = 0;
		if ((map[y][0] != '1' || map[y][strlen(map[y]) - 2] != '1'))
			return (0);
		while (map[y][x] != '\n')
		{
			if ((y == 0 || !map[y + 1]) && map[y][x] != '1')
				return (0);
			x++;
			if (y == 0)
				count = x;
		}
		if (count != x)
			return (0);
		y++;
	}
	return (1);
}

int	ft_check_char_rectangle(char **map, char c)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x] != 0)
		{
			if (map[y][x] == c)
				count++;
			if (map[y][x] != '1' && map[y][x] != '0' &&
			map[y][x] != 'C' && map[y][x] != 'P' && map[y][x] != 'E')
				return (0);
			x++;
		}
		y++;
	}
	if (x == y)
		return (0);
	return (count);
}

int	ft_map_checker(t_game *game)
{
	if (!game->map)
		return (0);
	if (ft_check_char_rectangle(game->map, 'C') < 1)
		return (0);
	if (ft_check_char_rectangle(game->map, 'E') != 1)
		return (0);
	if (ft_check_char_rectangle(game->map, 'P') != 1)
		return (0);
	if (!ft_check_sides(game->map))
		return (0);
	return (1);
}
