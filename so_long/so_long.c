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

int	ft_free(t_vars *vars)
{
	(void)vars;
	return (0);
}

void	ft_setup_vars(t_vars *vars, void *mlx, void *mlx_win)
{
	char	*file;
	int		width;
	int		height;

	vars->img->img = mlx_new_image(mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, &vars->img->line_length, &vars->img->endian);
	vars->mlx = mlx;
	vars->win = mlx_win;
	vars->x_player = 0;
	vars->y_player = 0;
	vars->moove = 0;
	vars->score = 0;
	file = "assets/font.xpm";
	vars->sprite->map = mlx_xpm_file_to_image(vars->mlx, file, &width, &height);
	file = "assets/shrek.xpm";
	vars->sprite->shrek = mlx_xpm_file_to_image(vars->mlx, file, &width, &height);
	file = "assets/piece.xpm";
	vars->sprite->piece = mlx_xpm_file_to_image(vars->mlx, file, &width, &height);
	file = "assets/alban.xpm";
	vars->sprite->house = mlx_xpm_file_to_image(vars->mlx, file, &width, &height);
}

int    so_long(void *mlx, void *mlx_win)
{
	t_vars	*vars;
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->img = malloc(sizeof(t_data));
	if (!vars->img)
		return (ft_free(vars));
	vars->sprite = malloc(sizeof(t_sprite));
	if (!vars->sprite)
		return (ft_free(vars));
	ft_setup_vars(vars, mlx, mlx_win);
	ft_setup_hook(vars);
	mlx_loop_hook(mlx, render_next_frame, vars);
	mlx_loop(mlx);
	return (0);
}
