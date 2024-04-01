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

#include "../inc/push_swap.h"

t_stack	*ft_three_solver(t_stack *stack_a)
{
	if (stack_a->next->num > stack_a->num
		&& stack_a->next->num > stack_a->next->next->num)
	{
		stack_a = ft_swap_stack(stack_a, 'a');
		stack_a = ft_rotate_stack(stack_a, 'a');
	}
	else if (stack_a->num > stack_a->next->num
		&& stack_a->num > stack_a->next->next->num)
		stack_a = ft_rotate_stack(stack_a, 'a');
	if (stack_a->num > stack_a->next->num)
		stack_a = ft_swap_stack(stack_a, 'a');
	return (stack_a);
}

t_stack	*ft_four_solver(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	while (stack_b == NULL)
	{
		if (stack_a->place == 1)
		{
			temp = stack_a;
			stack_a = ft_push_stack(stack_a, stack_b, 'b');
			stack_b = temp;
		}
		else
			stack_a = ft_rotate_stack(stack_a, 'a');
	}
	stack_a = ft_three_solver(stack_a);
	temp = stack_b;
	ft_push_stack(stack_b, stack_a, 'a');
	stack_a = temp;
	return (stack_a);
}

t_stack	*ft_five_solver(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	while (stack_b == NULL || stack_b->next == NULL)
	{
		if (stack_a->place == 1 || stack_a->place == 2)
		{
			temp = stack_a;
			stack_a = ft_push_stack(stack_a, stack_b, 'b');
			stack_b = temp;
		}
		else
			stack_a = ft_rotate_stack(stack_a, 'a');
	}
	stack_a = ft_three_solver(stack_a);
	if (stack_b->place == 1)
		stack_b = ft_swap_stack(stack_b, 'b');
	while (stack_b)
	{
		temp = stack_b;
		stack_b = ft_push_stack(stack_b, stack_a, 'a');
		stack_a = temp;
	}
	return (stack_a);
}

void	ft_easy_solver(t_stack *stack_a, t_stack *temp, int argc)
{
	if (argc == 3 && stack_a->num > stack_a->next->num)
		stack_a = ft_swap_stack(stack_a, 'a');
	if (argc == 4)
		stack_a = ft_three_solver(stack_a);
	if (argc == 5)
		stack_a = ft_four_solver(stack_a, NULL);
	if (argc == 6)
		stack_a = ft_five_solver(stack_a, NULL);
	ft_free_stack(stack_a, temp, 0);
}
