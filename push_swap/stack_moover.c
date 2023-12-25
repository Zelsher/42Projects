/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:17:27 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 10:17:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rotate_stack(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*current;

	ft_printf("r%c\n", stack_a->stack);
	temp = stack_a->next;
	current = stack_a;
	while (current->next)
		current = current->next;
	current->next = stack_a;
	stack_a->next = NULL;
	return (temp);
}

t_stack	*ft_reverse_stack(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*current;

	ft_printf("rra\n");
	current = stack_a;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = stack_a;
	return (temp);
}

t_stack	*ft_push_stack(t_stack *pushed_stack, t_stack *receiver)
{
	t_stack	*temp;

	ft_printf("p%c\n", pushed_stack->stack);
	temp = pushed_stack->next;
	pushed_stack->next = receiver;
	if (pushed_stack->stack == 'a')
		pushed_stack->stack = 'b';
	else
		pushed_stack->stack = 'a';
	return (temp);
}

t_stack	*ft_swap_stack(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*first;

	ft_printf("s%c\n", stack_a->stack);
	temp = stack_a->next->next;
	first = stack_a->next;
	stack_a->next = temp;
	first->next = stack_a;
	return (first);
}
