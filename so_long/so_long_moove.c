/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moove_player_valid(t_game *game, int keycode)
{
	int	i;

	i = 0;
	if ((keycode == 100 || keycode == 65363))
		if (game->map[game->y_player][game->x_player + 1] != '1')
			i = 1;
	if ((keycode == 97 || keycode == 65361))
		if (game->map[game->y_player][game->x_player - 1] != '1')
			i = 1;
	if (keycode == 115 || keycode == 65364)
		if (game->map[game->y_player + 1][game->x_player] != '1')
			i = 1;
	if (keycode == 119 || keycode == 65362)
		if (game->map[game->y_player - 1][game->x_player] != '1')
			i = 1;
	if (i == 1)
	{
		game->moove++;
		return (1);
	}
	return (0);
}

int	moove_player(t_game *game, int keycode)
{
	if ((keycode == 100 || keycode == 65363)
		&& moove_player_valid(game, keycode))
		game->x_player += 1;
	if ((keycode == 97 || keycode == 65361)
		&& moove_player_valid(game, keycode))
		game->x_player -= 1;
	if ((keycode == 115 || keycode == 65364)
		&& moove_player_valid(game, keycode))
		game->y_player += 1;
	if ((keycode == 119 || keycode == 65362)
		&& moove_player_valid(game, keycode))
		game->y_player -= 1;
	if (game->score == 0 && (game->x_player == game->x_exit
			&& game->y_player == game->y_exit))
		game->score = 1;
	ft_printf("Moove : %d\n", game->moove);
	ft_printf("Player : %dx%d\n", game->x_player, game->y_player);
	return (0);
}
