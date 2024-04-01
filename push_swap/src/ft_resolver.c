/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:13:27 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 11:13:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_index_placer(t_stack *stack_a)
{
	int	i;

	i = 1;
	while (stack_a)
	{
		stack_a->place = i;
		i++;
		stack_a = stack_a->next;
	}
}

void	swap(t_stack *a, t_stack *b)
{
	int	temp;

	temp = a->num;
	a->num = b->num;
	b->num = temp;
}

// Sorts the given stack in ascending order using bubble sort
t_stack	*ft_resolver(t_stack *stack_a, t_stack *current)
{
	while (current->next)
	{
		if (current->num > current->next->num)
		{
			swap(current, current->next);
			current = stack_a;
		}
		else
			current = current->next;
	}
	ft_index_placer(stack_a);
	return (stack_a);
}
