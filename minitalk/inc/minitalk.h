/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:55:08 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/07 18:55:08 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../Libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_data
{
	int		i;
	int		bit;
	int		pid;
	int		verif;
	int		c_pid;
	int		s_pid;
	int		str_len;
	char	*str;
	char	*p_str;
}					t_data;

#endif