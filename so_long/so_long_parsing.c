/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_copy(t_game *game, int y, int x)
{
	char	**map;

	y = 0;
	map = malloc(sizeof(char *) * (game->height + 1));
	if (!map)
		ft_free(game, 5, 1);
	while (game->map[y])
	{
		x = 0;
		map[y] = malloc(sizeof(char) * (game->width + 2));
		if (!map[y])
			return (ft_free_map(map), ft_free(game, 5, 1), map);
		map[y + 1] = NULL;
		if (!map[y])
			return (ft_free_map(map), ft_free(game, 5, 1), map);
		while (game->map[y][x])
		{
			map[y][x] = game->map[y][x];
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	return (map);
}

int	ft_path_verificator(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

t_Point	new_point(int y, int x)
{
	t_Point	a;

	a.col = x;
	a.row = y;
	return (a);
}

void	ft_fill_path(char **map, int y, int x, t_Point *stack)
{
	t_Point	current;
	int		top;

	top = 0;
	stack[top] = new_point(y, x);
	while (top >= 0)
	{
		current = stack[top--];
		y = current.row;
		x = current.col;
		map[y][x] = 'X';
		if (map[y][x + 1] != '1' && map[y][x + 1] != 'X')
			stack[++top] = new_point(y, x + 1);
		if (map[y][x - 1] != '1' && map[y][x - 1] != 'X')
			stack[++top] = new_point(y, x - 1);
		if (map[y + 1][x] != '1' && map[y + 1][x] != 'X')
			stack[++top] = new_point(y + 1, x);
		if (map[y - 1][x] != '1' && map[y - 1][x] != 'X')
			stack[++top] = new_point(y - 1, x);
	}
	free(stack);
}

int	ft_parsing_check(t_game *game)
{
	char	**map;
	t_Point	*stack;

	map = ft_map_copy(game, 0, 0);
	if (!map)
		ft_free(game, 5, 1);
	stack = (t_Point *)malloc(sizeof(t_Point) * game->height * game->width);
	if (!stack)
		return (ft_free_map(map), ft_free(game, 5, 1), 1);
	ft_fill_path(map, game->y_player, game->x_player, stack);
	if (!ft_path_verificator(map))
	{
		ft_printf("Error map\n");
		ft_free_map(map);
		ft_free(game, 5, 1);
	}
	ft_free_map(map);
	return (1);
}
