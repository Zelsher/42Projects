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

t_stack	*ft_three_solver(t_stack *stack_a)
{
	if (stack_a->num > stack_a->next->next->num)
		stack_a = ft_rotate_stack(stack_a);
	if (stack_a->num > stack_a->next->num)
		stack_a = ft_swap_stack(stack_a);
	return (stack_a);
}

void	ft_easy_solver(t_stack *stack_a, int argc)
{
	if (argc == 3)
		stack_a = ft_three_sovoler(stack_a);
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