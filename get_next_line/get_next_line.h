/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:05:46 by eboumaza          #+#    #+#             */
/*   Updated: 2023/09/12 22:05:46 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);

#endif