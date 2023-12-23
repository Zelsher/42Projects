/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:05:56 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/29 18:05:56 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"
#include <stdio.h>

long int	ft_random(int len)
{
	long int	num;
	int			fd;
	char		*str;

	fd = open("/proc/uptime", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	num = 5;
	return (num);
}

main()
{
	ft_random(5);
	return(0);
}