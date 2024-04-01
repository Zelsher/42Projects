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
# define FONT "assets/font.xpm"
# define SHREK "assets/shrek.xpm"
# define COIN  "assets/coin.xpm"
# define END_SCREEN "assets/end_screen.xpm"
# define WALL "assets/wall.xpm"
# define HOUSE "assets/house.xpm"

# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_sprite
{
	void	*font;
	void	*shrek;
	void	*coin;
	void	*wall;
	void	*house;
	void	*end_screen;
}			t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			moove;
	int			score;
	int			width;
	int			height;
	int			x_player;
	int			y_player;
	int			x_exit;
	int			y_exit;
	int			**coin;
	char		**map;
	t_sprite	*sprite;
	t_data		*img;
}				t_game;

typedef struct s_point
{
	int	row;
	int	col;
}			t_Point;

int		create_trgb1(unsigned char t, unsigned char r, unsigned char g,
			unsigned char b);
int		get_t1(int trgb);
int		get_r1(int trgb);
int		get_g1(int trgb);
int		get_b1(int trgb);
int		add_shade(double shade, int color);
int		get_opposite(int color);

void	ft_free_map(char **map);
void	ft_free(t_game *game, int to_free, int return_value);

int		ft_parsing_check(t_game *game);
int		ft_map_checker(t_game *game);
void	ft_map_filler(char *file, t_game *game);
t_game	*ft_game_init(t_game *game, int width, int height);

int		moove_player_valid(t_game *game, int keycode);
int		moove_player(t_game *game, int keycode);
void	ft_setup_hook(t_game *game);

int		render_next_frame(t_game *game);
int		so_long(t_game *game);

#endif
