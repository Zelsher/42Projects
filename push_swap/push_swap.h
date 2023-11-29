/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:17:34 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 10:17:36 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				num;
	char			place;
	int				max_digit;
	char			stack;
	struct s_stack	*next;
}					t_stack;

int			ft_free_stack(t_stack *stack_a, t_stack *temp);
int			ft_printer(t_stack *stack_a, t_stack *stack_b);
t_stack		*ft_newstack(int content, int place, char c);
void		ft_radix(t_stack *stack_a, t_stack *temp);

int			ft_digit_counter(int digit);
t_stack		*ft_resolver(t_stack *stack_a, t_stack *before, t_stack *current);

t_stack		*ft_reverse_stack(t_stack *stack_a);
t_stack		*ft_push_stack(t_stack *stack_a, t_stack *stack_b);

#endif