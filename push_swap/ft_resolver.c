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

#include "push_swap.h"

int	ft_trior(t_stack *before, t_stack *current)
{
	t_stack	*temp;

	if (current->num > current->next->num)
	{
		temp = current->next->next;
		current->next->next = current;
		if (before)
			before->next = current->next;
		current->next->place--;
		current->next = temp;
		current->place++;
		return (1);
	}
	return (0);
}

/*Ft_resolver et ft_add sont le fruit d'une separation en deux,
ft_ad sert a reduire la taille de ft_resolver*/

t_stack	*ft_ad(t_stack *fir_p, t_stack *sec_p, char *stack)
{
	if (!ft_strcmp(stack, "stack_a"))
		return (fir_p);
	if (!ft_strcmp(stack, "before"))
	{
		if (fir_p->place >= 4)
			return (sec_p);
		else
			return (NULL);
	}
	if (!ft_strcmp(stack, "befores"))
	{
		while (sec_p && fir_p->place >= 4 && sec_p->next->next->next != fir_p)
			sec_p = sec_p->next;
		return (sec_p);
	}
	else
	{
		if (fir_p)
			return (fir_p->next);
		else
			return (sec_p);
	}
}

t_stack	*ft_resolver(t_stack *stack_a, t_stack *before, t_stack *current)
{
	t_stack	*temp;
	int		i;

	while (current && current->next)
	{
		temp = current->next;
		i = ft_trior(before, current);
		if (i == 0)
		{
			before = current;
			current = current->next;
		}
		if (i == 1)
		{
			if (current->place == 2)
				stack_a = ft_ad(temp, NULL, "stack_a");
			before = ft_ad(current, stack_a, "before");
			before = ft_ad(current, before, "befores");
			current = ft_ad(before, stack_a, "current");
		}
	}
	return (stack_a);
}
