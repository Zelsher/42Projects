/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:34:24 by eboumaza          #+#    #+#             */
/*   Updated: 2024/04/28 15:18:08 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosopher.h"

int	is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);	
}

void	FREE_philo(t_watcher *watcher)
{
	(void)watcher;
}
