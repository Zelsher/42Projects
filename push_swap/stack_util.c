/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:17:27 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 10:17:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_digit_counter(int digit)
{
	int	counter;

	counter = 1;
	while (digit > 10)
	{
		digit = digit / 10;
		counter++;
	}
	return (digit);
}

t_stack	*ft_newstack(int num, int place, char c)
{
	t_stack	*newlist;

	newlist = malloc(sizeof(t_stack));
	if (newlist == NULL)
		return (NULL);
	newlist->num = num;
	newlist->place = place;
	newlist->max_digit = ft_digit_counter(num);
	newlist->stack = c;
	newlist->next = NULL;
	return (newlist);
}

int	ft_free_stack(t_stack *stack_a, t_stack *temp)
{
	t_stack	*next;

	while (stack_a)
	{
		next = stack_a->next;
		free(stack_a);
		stack_a = next;
	}
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	return (0);
}

t_stack	*ft_reverse_stack(t_stack *stack_a)
{
	t_stack	*temp;
	t_stack	*current;

	ft_printf("ra\n");
	temp = stack_a->next;
	current = stack_a;
	while (current->next)
		current = current->next;
	current->next = stack_a;
	stack_a->next = NULL;
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
