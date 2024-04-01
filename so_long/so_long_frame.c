/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_scorer(t_game *game)
{
	int	i;

	i = 0;
	if (game->score == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite->house, game->x_exit * 120, game->y_exit * 120);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprite->font, game->x_exit * 120, game->y_exit * 120);
	while (game->coin[i] != 0)
	{
		if (game->coin[i][2] && (game->coin[i][1] == game->x_player
			&& game->coin[i][0] == game->y_player))
		{
			game->score++;
			game->coin[i][2] = 0;
		}
		if (game->coin[i][2])
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->coin,
				game->coin[i][1] * 120, game->coin[i][0] * 120);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->sprite->font,
				game->coin[i][1] * 120, game->coin[i][0] * 120);
		i++;
	}
}

void	ft_put_font(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((game->map[i][j] == 'P' || game->map[i][j] == '0')
				&& (i != game->y_player || j != game->x_player))
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprite->font, j * 120, i * 120);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->sprite->wall, j * 120, i * 120);
			j++;
		}
		i++;
	}
}

int	render_next_frame(t_game *game)
{
	if (game->score == 1)
		ft_free(game, 5, 0);
	else
	{
		ft_put_font(game);
		ft_scorer(game);
		mlx_put_image_to_window (game->mlx, game->win, game->sprite->shrek,
			game->x_player * 120, game->y_player * 120);
	}
	return (0);
}
