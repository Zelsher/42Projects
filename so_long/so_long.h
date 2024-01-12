/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MLX_ERROR 1
# define  IMAGE_WIDTH 1920
# define  IMAGE_HEIGHT 1080

# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_sprite{
	void	*map;
	void	*shrek;
	void	*piece;
	void	*house;
}			t_sprite;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	int			score;
	int			x_player;
	int			y_player;
	int			moove;
	t_sprite	*sprite;
	t_data		*img;
}				t_vars;

int		create_trgb1(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
int		get_t1(int trgb);
int		get_r1(int trgb);
int		get_g1(int trgb);
int		get_b1(int trgb);
int 	add_shade(double shade, int color);
int 	get_opposite(int color);

void    ft_setup_hook(t_vars *vars);
void	my_mlx_pixelput(t_data *data, int x, int y, int color);

int		render_next_frame(t_vars *vars);
int		so_long(void *mlx, void *mlx_win);

#endif