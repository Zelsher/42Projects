/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_helper(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		game->x_player = x;
		game->y_player = y;
	}
	if (game->map[y][x] == 'E')
	{
		game->x_exit = x;
		game->y_exit = y;
	}
}

int	ft_malloc_coin(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\n')
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	game->coin = malloc(sizeof(int *) * (count + 1));
	if (!game->coin)
		ft_free(game, 1, 1);
	return (1);
}

void	ft_placer(t_game *game, int count, int y, int x)
{
	ft_malloc_coin(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_helper(game, x, y);
			if (game->map[y][x] == 'C')
			{
				game->coin[count] = malloc(sizeof(int) * 3);
				if (!game->coin[count])
					ft_free(game, 2, 1);
				game->coin[count][0] = y;
				game->coin[count][1] = x;
				game->coin[count][2] = 1;
				count++;
				game->score--;
			}
			x++;
		}
		y++;
	}
	game->coin[count] = 0;
}

void	ft_set_sprite(t_game *game, int width, int height)
{
	game->sprite->font = mlx_xpm_file_to_image
		(game->mlx, FONT, &width, &height);
	game->sprite->shrek = mlx_xpm_file_to_image
		(game->mlx, SHREK, &width, &height);
	game->sprite->coin = mlx_xpm_file_to_image
		(game->mlx, COIN, &width, &height);
	game->sprite->end_screen = mlx_xpm_file_to_image
		(game->mlx, END_SCREEN, &width, &height);
	game->sprite->wall = mlx_xpm_file_to_image
		(game->mlx, WALL, &width, &height);
	game->sprite->house = mlx_xpm_file_to_image
		(game->mlx, HOUSE, &width, &height);
}

t_game	*ft_game_init(t_game *game, int width, int height)
{
	game->score = 0;
	ft_placer(game, 0, 0, 0);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_free(game, 2, 1);
	game->win = mlx_new_window
		(game->mlx, game->width * 120, game->height * 120, "so_long");
	if (!game->win)
		ft_free(game, 3, 1);
	game->sprite = malloc(sizeof(t_sprite));
	if (!game->sprite)
		ft_free(game, 4, 1);
	game->moove = 0;
	ft_set_sprite(game, width, height);
	return (game);
}
