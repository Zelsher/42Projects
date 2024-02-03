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

void	ft_free_parsing_map(t_game *finder, t_game *game, int return_value)
{
	(void)finder;
	ft_free(game, 1, return_value);
}

void	ft_print_map(char **map, t_pathfinding finder, int y_coin, int x_coin)
{
	int	i;
	char	temp;
	char	temp2;

	i = 0;
	temp = map[finder.y][finder.x];
	map[finder.y][finder.x] = 'G';
	temp2 = map[finder.y][finder.x];
	map[y_coin][x_coin] = 'C';
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	i = 0;
	map[finder.y][finder.x] = temp;
	map[y_coin][x_coin] = temp2;
	ft_printf("\n");
}

int	ft_malloc_path(t_pathfinding *finder, int i, int j)
{
	int	**temp;
	temp = finder->path;
	while (finder->path && finder->path[i + j])
	{
		if (finder->map[finder->path[i + j][0]][finder->path[i + j][1]] != '0')
			i++;
		else
			j++;
	}
	finder->path_num = i;
	ft_printf("malloc de %i\n", i + 2);
	finder->path = malloc(sizeof(int *) * i + 4);
	if (!finder->path)
		return (0);
	i = 0;
	j = 0;
	while (i < finder->path_num)
	{
		if (temp[i + j] && finder->map[temp[i + j][0]][temp[i + j][1]] != '0')
		{
			finder->path[i] = malloc(sizeof(int) * 2);
			if (!finder->path[i])
				return (0);
			finder->path[i][0] = temp[i + j][0];
			finder->path[i][1] = temp[i + j][1];
			ft_printf("%d : %dx%d\n", i, finder->path[i][0], finder->path[i][1]);
			i++;
		}
		else
			j++;
	}
	finder->path[i] = malloc(sizeof(int) * 2);
	if (!finder->path[i])
		return (0);
	finder->path[i][0] = finder->y;
	finder->path[i][1] = finder->x;
	finder->path[i + 1] = NULL;
	ft_printf("%dx%d added at %d\n", finder->path[i][0], finder->path[i][1], i);
	ft_printf("path_num : %d\n\n", finder->path_num);
	return (1);
}

int	already_went(t_pathfinding *finder, int y, int x)
{
	int	i;
	
	i = 0;
	if (!finder->path)
		return (0);
	while (finder->path[i])
	{
		if (finder->path[i][0] == y && finder->path[i][1] == x)
			return (1);
		i++;
	}
	return (0);
}

void	ft_next_moove(t_pathfinding *finder, t_game *game)
{
	if (finder->map[finder->y][finder->x] > '1')
	{
		if (!ft_malloc_path(finder, 0, 0))
		{
			finder->path = NULL;
			ft_free(game, 1, 1);
		}
	}
	if (finder->map[finder->y][finder->x] > '0')
		finder->map[finder->y][finder->x] -= 1;
	if (finder->x != game->width && finder->map[finder->y][finder->x + 1] >'1'
	&& !already_went(finder, finder->y, finder->x + 1))
		finder->x++;
	else if (finder->x != 0 && finder->map[finder->y][finder->x - 1] > '1'
	&& !already_went(finder, finder->y, finder->x - 1))
		finder->x--;
	else if (finder->y != 0 && finder->map[finder->y - 1][finder->x] > '1'
	&& !already_went(finder, finder->y - 1, finder->x))
		finder->y--;
	else if (finder->y != game->height && finder->map[finder->y + 1][finder->x] > '1'
	&& !already_went(finder, finder->y + 1, finder->x))
		finder->y++;
	if (finder->map[finder->y][finder->x] > '0')
		finder->map[finder->y][finder->x] -= 1;
}

int	ft_path_checker(t_game *game, char **parsing_map, int x_coin, int y_coin)
{
	t_pathfinding	finder;

	finder.x = game->x_player;
	finder.y = game->y_player;
	finder.map = parsing_map;
	finder.path = NULL;
	finder.path_num = 0;
	while (parsing_map[finder.y][finder.x] != '0')
	{
		while(parsing_map[finder.y][finder.x] != '0')
		{
			ft_next_moove(&finder, game);
			ft_print_map(parsing_map, finder, y_coin, x_coin);
			if (finder.x == x_coin && finder.y == y_coin)
			{
				ft_printf("::::::::::UN CHEMIN A ETE TROUVE POUR LE COIN %dx%d : %dx%d::::::::::\n\n=========MAP=========\n", y_coin, x_coin, finder.y, finder.x);
				return (1);
			}
		}
		if (finder.path[finder.path_num])
		{
			while (finder.map[finder.path[finder.path_num][0]][finder.path[finder.path_num][1]] == '0')
				finder.path_num--;
			ft_printf("go to %dx%d\n\n", finder.path[finder.path_num][0], finder.path[finder.path_num][1]);
			finder.y = finder.path[finder.path_num][0];
			finder.x = finder.path[finder.path_num][1];
			finder.path_num--;
			if (finder.path_num == -1)
			{
				finder.path = NULL;
			}
			ft_printf("pathnum verif %d\n", finder.path_num);
		}
	}
	ft_printf("::::::::::AUCUN CHEMIN N'A ETE TROUVE POUR LE COIN %dx%d::::::::::\n\n", y_coin, x_coin);
	return (0);
}

void	ft_path_filler(t_game *game, char **parsing_map, int x, int y)
{
	int	path_number;


	path_number = 0;
	if (x != 0)
	{
		if (game->map[y][x - 1] != '1')
			path_number++;
	}
	if (x != game->width)
	{
		if (game->map[y][x + 1] != '1')
			path_number++;
	}
	if (y != 0)
	{
		if (game->map[y - 1][x] != '1')
			path_number++;
	}
	if (y != game->height)
	{
		if (game->map[y + 1][x] != '1')
			path_number++;
	}
	parsing_map[y][x] = path_number + '0';
}

char	**ft_fill_parsing_map(t_game *game, char **parsing_map)
{
	int	y;
	int	x;

	y = 0;
	ft_printf("\n");
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\n')
		{
			if (game->map[y][x] == '1')
				parsing_map[y][x] = '0';
			else
				ft_path_filler(game, parsing_map, x, y);
			x++;
		}
		y++;
	}
	return (parsing_map);
}

int ft_parsing_check(t_game *game)
{
	char	**parsing_map;
	int		i;

	i = 0;
	parsing_map = malloc(sizeof(char *) * game->height + 2);
	if (!parsing_map)
		ft_free(game, 1, 1);
	while (game->height != i)
	{
		parsing_map[i] = malloc(sizeof(char) * game->width + 2);
		if (!parsing_map[i])
			ft_free(game, 1, 1);
		parsing_map[i][game->width + 1] = '\0';
		i++;
	}
	parsing_map[i] = NULL;
	i = 0;
	while (i != 3)
	{
		ft_printf("%d\n", i);
		if (!ft_path_checker(game, ft_fill_parsing_map(game, parsing_map), game->coin[i][0], game->coin[i][1]))
			ft_free(game, 1, 1);
		i++;
	}
	ft_printf("%d\n", i);
	//if (!ft_path_checker(game, ft_fill_parsing_map(game, parsing_map), game->y_exit, game->x_exit))
	//		ft_free(game, 1, 1);
	ft_printf("%d\n", i);
	return (1);
}
int add_shade(double shade, int color)
{
    int t;
    int r;
    int g;
    int b;

    t = get_t1(color);
    r = get_r1(color) * shade;
    g = get_g1(color) * shade;
    b = get_b1(color) * shade;
    return (create_trgb1(t, r, g, b));
}

int get_opposite(int color)
{
    int t;
    int r;
    int g;
    int b;

    t = get_t1(color);
    r = 255 - get_r1(color);
    g = 255 - get_g1(color);
    b = 255 - get_b1(color);
    return (create_trgb1(t, r, g, b));
}