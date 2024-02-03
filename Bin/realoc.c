char	**ft_realoc_tab_tab(char **map, char *new_str)
{
	char	**new_map;
	int		i;

	i = 0;
	while(map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 2));
	if (!new_map)
		return(NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = malloc(sizeof(char) * (strlen(map[i]) + 1));
		if (!new_map[i])
		{
			ft_free_map(map);
			ft_free(new_map, 1, 1);
		}
		strcpy(new_map[i], map[i]);
		free(map[i]);
		i++;
	}
	new_map[i] = new_str;
	new_map[i + 1] = NULL;
	free(map);
	return(new_map);
}

void	ft_parsing_map(char **map, char **ft_parsing_map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			x++;
		}
		y++;
	}
}
