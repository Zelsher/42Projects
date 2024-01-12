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

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars);
	exit(0);
}

int	moove_player(t_vars *vars, int keycode)
{
	if ((keycode == 100 || keycode == 65363) && vars->x_player < IMAGE_WIDTH - 200)
	{
		vars->x_player += 20;
		vars->moove++;
	}
	if ((keycode == 97 || keycode == 65361) && vars->x_player > 0)
	{
		vars->x_player -= 20;
		vars->moove++;
	}
	if ((keycode == 115 || keycode == 65364) && vars->y_player < IMAGE_HEIGHT - 200)
	{
		vars->y_player += 20;
		vars->moove++;
	}
	if ((keycode == 119 || keycode == 65362) && vars->y_player > 0)
	{
		vars->y_player -= 20;
		vars->moove++;
	}
	ft_printf("moove : %d\n", vars->moove);
	return (0);
}

int	keybind(int keycode, t_vars *vars)
{
	ft_printf("Keypressed : %d\n", keycode);
	if (keycode == 65307)
		close_win(vars);
	if (keycode == 115 || keycode == 119 || keycode == 97 || keycode == 100 ||
		keycode == 65363 || keycode == 65361 || keycode == 65364 || keycode == 65362)
		moove_player(vars, keycode);
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	ft_printf("MOUSE : %d\n", keycode);
	(void)vars;
	return (0);
}

int	mouse_moove(int x, int y, t_vars *vars)
{
	ft_printf("PLACE : X=%d | Y=%d\n", x, y);
	(void)vars;
	return (0);
}

void    ft_setup_hook(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L<<0, keybind, vars);
	mlx_hook(vars->win, 17, 1L<<0, close_win, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	mlx_hook(vars->win, 6, 1L<<6, mouse_moove, vars);
}
