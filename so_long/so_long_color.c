/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb1(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	get_t1(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r1(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g1(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b1(int trgb)
{
	return (trgb & 0xFF);
}

int add_shade(double shade, int color)
{
    int t;
    int r;
    int g;
    int b;

    t = get_t1(color);
    r = get_r1(color) * shade;
    g = get_g1(color) * shade;
    b = get_b1(color) * shade;
    return (create_trgb1(t, r, g, b));
}

int get_opposite(int color)
{
    int t;
    int r;
    int g;
    int b;

    t = get_t1(color);
    r = 255 - get_r1(color);
    g = 255 - get_g1(color);
    b = 255 - get_b1(color);
    return (create_trgb1(t, r, g, b));
}

/*void	test(t_vars *vars)
{
	int     color;
	int     clr1;
	int     clr2;
	int     clr3;
	int     i;
	int     j;
	int		seed;

	seed = ft_random_seed(0);
	clr1 = ft_random(seed, 255, 0);
	seed = ft_random_seed(seed);
	clr2 = ft_random(seed, 255, 0);
	seed = ft_random_seed(seed);
	clr3 = ft_random(seed, 255, 0);
	seed = ft_random_seed(seed);
	color = create_trgb1(0, clr1, clr2, clr3);
	i = 20;
	while (i <= 680)
	{
		j = 20;
		while(j <= 910)
		{
			my_mlx_pixelput(vars->img, j, i, color);
			j++;
		}
		i++;
	}
}*/