/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber"))
		return (0);
	ft_map_filler(argv[1], &game);
	if (!ft_map_checker(&game))
	{
		ft_printf("Erreur de map\n");
		ft_free(&game, 1, 1);
	}
	ft_game_init(&game, 0, 0);
	if (!ft_parsing_check(&game))
		ft_free(&game, 5, 1);
	so_long(&game);
	return (0);
}
