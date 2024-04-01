/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:13:27 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 11:13:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	argv_verificator(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_iswspace(argv[i][j])
			&& !ft_isminorplus(argv[i][j]))
				return (ft_printf("Error\n"), 0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc != 2 && !argv_verificator(argv, argc))
		return (0);
	push_swap(argc, argv, NULL, NULL);
	return (0);
}
