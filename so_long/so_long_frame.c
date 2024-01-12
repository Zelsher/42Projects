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

void	ft_spriter(t_vars *vars)
{
    mlx_put_image_to_window (vars->mlx, vars->win, vars->sprite->house, 0, 0);
	mlx_put_image_to_window (vars->mlx, vars->win, vars->sprite->shrek, vars->x_player, vars->y_player);
	if (vars->score != 1 && vars->score != 3 && vars->score != 5 && vars->score != 7)
		mlx_put_image_to_window (vars->mlx, vars->win, vars->sprite->piece, 500, 500);
	if (vars->score != 2 && vars->score != 3 && vars->score != 6 && vars->score != 7)
		mlx_put_image_to_window (vars->mlx, vars->win, vars->sprite->piece, 1820, 980);
	if (vars->score != 4 && vars->score != 5 && vars->score != 6 && vars->score != 7)
		mlx_put_image_to_window (vars->mlx, vars->win, vars->sprite->piece, 1820, 0);
}

void	ft_loot(t_vars *vars)
{
	if (vars->score == 0 || vars->score == 2 ||
	vars->score == 4 || vars->score == 6)
	{
		if ((vars->x_player >= 300 && vars->y_player >= 300) &&
		(vars->x_player <= 700 && vars->y_player <= 700))
			vars->score += 1;
	}
	if (vars->score == 0 || vars->score == 1 ||
	vars->score == 4 || vars->score == 5)
	{
		if ((vars->x_player >= 1420 && vars->y_player >= 680))
			vars->score += 2;
	}
	if (vars->score == 0 || vars->score == 1 ||
	vars->score == 2 || vars->score == 3)
	{
		if ((vars->x_player >= 1620 && vars->y_player >= 0) && (vars->y_player <= 200))
			vars->score += 4;
	}
}

void	ft_endgame()
{
    exit(0);
}

int	render_next_frame(t_vars *vars)
{
	vars->img->img = ft_memcpy(vars->img->img, vars->sprite->map, 10);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	ft_loot(vars);
	ft_spriter(vars);
	if (vars->score == 7 && (vars->x_player <= 200 && vars->y_player <= 200))
		ft_endgame();
	return(0);
}
