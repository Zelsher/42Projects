/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_easy_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:13:27 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 11:13:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_easy_solver(t_stack *stack_a, int argc)
{
	(void)stack_a;
	(void)argc;
}

/*
{
	int		z;
	t_stack	*temp;
	t_stack	*stack_b;

	z = 0;
	stack_b = NULL;
	while (z < max_digit)
	{
		if ((stack_a->place & (1 << i)) == 0)
		{
			temp = stack_a;
			stack_a = ft_push_stack(stack_a, stack_b);
			stack_b = temp;
		}
		else
			stack_a = ft_reverse_stack(stack_a);
		z++;
	}
	while (stack_b)
	{
		temp = stack_b;
		stack_b = ft_push_stack(stack_b, stack_a);
		stack_a = temp;
	}
	return (stack_a);
}
*/