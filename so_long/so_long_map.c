/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_malloc_map(char *file, t_game *game, int i, int fd)
{
	char	*temp;
	char	**map;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Erreur de fichier\n"), ft_free(game, 0, 1), NULL);
	temp = get_next_line(fd);
	while (temp)
	{
		i++;
		free(temp);
		temp = get_next_line(fd);
	}
	if (temp)
		free (temp);
	if (i <= 2)
		return (close(fd), ft_printf("Erreur de MAP\n"), ft_free(game, 0, 1), NULL);
	map = malloc(sizeof(char *) * (i + 1));
	close(fd);
	if (!map)
		ft_free(game, 0, 1);
	map[0] = NULL;
	return (map);
}

void	ft_map_filler(char *file, t_game *game)
{
	int		i;
	int		fd;
	char	**map;

	i = 1;
	map = ft_malloc_map(file, game, 0, 0);
	game->map = map;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Erreur de fichier\n");
		ft_free(game, 1, 1);
	}
	map[0] = get_next_line(fd);
	while (map[i - 1])
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	game->width = ft_strlen(map[0]) - 1;
	game->height = i - 1;
}
