/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:17:27 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 10:17:28 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	argv_verificator(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_iswspace(argv[i][j]) 
			&& !ft_isminorplus(argv[i][j]))
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

static	t_stack	*stack_a_filler(char **argv, int argc, t_stack *stack_a)
{
	int		i;
	t_stack	*next;
	t_stack	*temp;

	i = 1;
	if (!stack_a)
		return (NULL);
	temp = stack_a;
	while (i < argc - 1)
	{
		i++;
		stack_a->next = ft_newstack(ft_atoi(argv[i]), i, 'a');
		if (!stack_a->next)
			return (NULL);
		stack_a = stack_a->next;
		next = temp;
		while (next != stack_a)
		{
			if (stack_a->num == next->num)
				return (NULL);
			next = next->next;
		}
	}
	return (temp);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*temp;

	if (argc == 1)
		return (0);
	if (!argv_verificator(argv, argc))
		return (0);
	stack_a = ft_newstack(ft_atoi(argv[1]), 1, 'a');
	temp = ft_newstack(ft_atoi(argv[1]), 1, 'a');
	stack_a_filler(argv, argc, stack_a);
	stack_a_filler(argv, argc, temp);
	if (!stack_a || !temp)
		return (ft_free_stack(stack_a, temp));
	ft_printf("Init a and b :\n");
	ft_radix(stack_a, temp);
	ft_free_stack(NULL, temp);
	return (0);
}
