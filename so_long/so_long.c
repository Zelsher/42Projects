/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	ft_print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		ft_printf("%s", map[y]);
		y++;
	}
	ft_printf("\n\n");
}
*/
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	ft_free_coin(t_game *game)
{
	int	i;

	i = 0;
	while (game->coin[i])
	{
		free(game->coin[i]);
		i++;
	}
	free(game->coin);
}

/*0 pour game, 1 pour map, 2 coin, 3 pour mlx, 4 pour win, 5 pour sprite*/
void	ft_free(t_game *game, int to_free, int return_value)
{
	if (to_free >= 1)
		ft_free_map(game->map);
	if (to_free >= 2)
		ft_free_coin(game);
	if (to_free >= 4)
		mlx_destroy_window(game->mlx, game->win);
	if (to_free == 5)
	{
		mlx_destroy_image(game->mlx, game->sprite->wall);
		mlx_destroy_image(game->mlx, game->sprite->coin);
		mlx_destroy_image(game->mlx, game->sprite->end_screen);
		mlx_destroy_image(game->mlx, game->sprite->font);
		mlx_destroy_image(game->mlx, game->sprite->house);
		mlx_destroy_image(game->mlx, game->sprite->shrek);
		free(game->sprite);
	}
	if (to_free >= 3)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	ft_printf("Closed by %d, Error code : %d\n", to_free, return_value);
	exit(return_value);
}

int	so_long(t_game *game)
{
	ft_setup_hook(game);
	mlx_loop_hook(game->mlx, render_next_frame, game);
	mlx_loop(game->mlx);
	return (0);
}
