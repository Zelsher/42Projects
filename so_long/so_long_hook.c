/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game)
{
	ft_free(game, 5, 0);
	return (0);
}

int	keybind(int keycode, t_game *game)
{
	//ft_printf("Keypressed : %d\n", keycode);
	if (keycode == 65307)
		close_win(game);
	if ((game->score != 8) && (keycode == 115 || keycode == 119
			|| keycode == 97 || keycode == 100 || keycode == 65363
			|| keycode == 65361 || keycode == 65364 || keycode == 65362))
		moove_player(game, keycode);
	return (0);
}

int	mouse_hook(int keycode, t_game *game)
{
	ft_printf("MOUSE : %d\n", keycode);
	(void)game;
	return (0);
}

void	ft_setup_hook(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, keybind, game);
	mlx_hook(game->win, 17, 1L << 0, close_win, game);
	mlx_mouse_hook(game->win, mouse_hook, game);
}
