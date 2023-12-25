/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:13:27 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 11:13:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_rotate_stack_checker(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*current;

	temp = stack_a->next;
	current = stack_a;
	while (current->next)
		current = current->next;
	current->next = stack_a;
	stack_a->next = NULL;
	return (temp);
}

t_stack	*ft_push_stack_checker(t_stack *pushed_stack, t_stack *receiver)
{
	t_stack	*temp;

	temp = pushed_stack->next;
	pushed_stack->next = receiver;
	if (pushed_stack->stack == 'a')
		pushed_stack->stack = 'b';
	else
		pushed_stack->stack = 'a';
	return (temp);
}

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
