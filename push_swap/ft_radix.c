/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:13:27 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 11:13:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_stack_placer(t_stack *stack_a, t_stack *temp)
{
	t_stack	*pointer_temp;
	t_stack	*pointer_a;

	pointer_a = stack_a;
	pointer_temp = temp;
	while (temp)
	{
		while (temp->num != stack_a->num && stack_a)
			stack_a = stack_a->next;
		temp->place = stack_a->place;
		temp = temp->next;
		stack_a = pointer_a;
	}
	ft_free_stack(stack_a, NULL, 0);
	return (pointer_temp);
}

static t_stack	*ft_radixer(t_stack *stack_a, int max_digit, size_t i)
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
			stack_a = ft_rotate_stack(stack_a);
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

static int	ft_max_digit(t_stack *stack_a)
{
	int	max_digit;

	max_digit = stack_a->place;
	while (stack_a)
	{
		if (max_digit < stack_a->place)
			max_digit = stack_a->place;
		stack_a = stack_a->next;
	}
	return (max_digit);
}

void	ft_radix(t_stack *stack_a, t_stack *temp)
{
	size_t	i;
	size_t	y;
	int		max_digit;

	stack_a = ft_resolver(stack_a, stack_a);
	stack_a = ft_stack_placer(stack_a, temp);
	i = 1;
	temp = stack_a;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	if (i <= 5)
		return (ft_easy_solver(stack_a, i));
	y = 0;
	i = 0;
	max_digit = ft_max_digit(stack_a);
	while (max_digit >> y != 0)
		y++;
	while (y >= i)
	{
		stack_a = ft_radixer(stack_a, max_digit, i);
		i++;
	}
}
