/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:05:42 by eboumaza          #+#    #+#             */
/*   Updated: 2023/09/12 22:05:42 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len;
	char	*joiner;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joiner = malloc(sizeof(char) * len);
	if (joiner == NULL)
		return (NULL);
	while (s1[i])
	{
		joiner[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2[i])
	{
		joiner[i + len] = s2[i];
		i++;
	}
	joiner[i + len] = '\0';
	return (joiner);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, src));
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	if (ch == 0)
		return ((char *)str + i);
	return (NULL);
}
