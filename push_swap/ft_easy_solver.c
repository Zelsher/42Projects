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

int	ft_printer(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	temp = stack_a;
	ft_printf("\n");
	while (temp)
	{
		ft_printf("%d ", temp->place);
		temp = temp->next;
	}
	ft_printf("\n___________________________\n");
	while (stack_a)
	{
		ft_printf("%d ", stack_a->num);
		stack_a = stack_a->next;
	}
	ft_printf("| a\n");
	while (stack_b)
	{
		ft_printf("%d ", stack_b->num);
		stack_b = stack_b->next;
	}
	ft_printf("|b\n\n---------------------------------------------------\n");
	return (1);
}

t_stack	*ft_three_solver(t_stack *stack_a)
{
	while (stack_a->num > stack_a->next->num 
		|| stack_a->next->num > stack_a->next->next->num)
	{
		if (stack_a->num < stack_a->next->num)
			stack_a = ft_swap_stack(stack_a);
		stack_a = ft_rotate_stack(stack_a);
	}
	ft_printer(stack_a, NULL);
	return (stack_a);
}

void	ft_four_solver(t_stack *stack_a)
{
	t_stack	*stack_b;
	t_stack	*temp;

	stack_b = NULL;
	while (stack_b == NULL)
	{
		if (stack_a->place == 1)
		{
			temp = stack_a;
			stack_a = ft_push_stack(stack_a, stack_b);
			stack_b = temp;
		}
		else
			stack_a = ft_rotate_stack(stack_a);
	}
	stack_a = ft_three_solver(stack_a);
	ft_printf("pb\n");
	ft_printer(stack_a, stack_b);
}

void	ft_five_solver(t_stack *stack_a)
{
	t_stack	*stack_b;
	t_stack	*temp;

	stack_b = NULL;
	while (stack_b == NULL || stack_b->next == NULL)
	{
		if (stack_a->place == 1 || stack_a->place == 2)
		{
			temp = stack_a;
			stack_a = ft_push_stack(stack_a, stack_b);
			stack_b = temp;
		}
		else
			stack_a = ft_rotate_stack(stack_a);
	}
	stack_a = ft_three_solver(stack_a);
	if (stack_b->place == 1)
		stack_b = ft_swap_stack(stack_b);
	ft_printf("pb\npb\n");
	ft_printer(stack_a, stack_b);
}

void	ft_easy_solver(t_stack *stack_a, int argc)
{
	if (argc == 3)
		stack_a = ft_three_solver(stack_a);
	if (argc == 4)
		ft_four_solver(stack_a);
	if (argc == 5)
		ft_five_solver(stack_a);
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