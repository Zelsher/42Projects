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

#include "../inc/push_swap.h"

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

void	ft_free_stack(t_stack *stack_a, t_stack *temp, int test)
{
	t_stack	*next;

	if (test == 1)
		ft_printf("Error\n");
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
}

int	ft_printer(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	temp = stack_a;
	ft_printf("\n");
	while (temp)
	{
		ft_printf("%d | ", temp->place);
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
