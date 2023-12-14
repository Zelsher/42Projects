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
#include <fcntl.h>

int	argv_verificator(char **argv, int argc)
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

int	ft_stack_verificator(t_stack *stack_a)
{
	int	temp;

	while (stack_a->next)
	{
		temp = stack_a->num;
		stack_a = stack_a->next;
		if (stack_a->num < temp)
			return (0);
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

int	ft_checker(t_stack *stack_a, char *instruct, int std)
{
	t_stack	*stack_b;
	t_stack	*temp;

	stack_b = NULL;
	while (instruct!= NULL && strcmp(instruct , "\n"))
	{
		if (!strcmp(instruct, "pa\n"))
		{
			temp = stack_a;
			stack_a = ft_push_stack_checker(stack_a, stack_b);
			stack_b = temp;
		}
		if (!strcmp(instruct, "ra\n"))
			stack_a = ft_rotate_stack_checker(stack_a);
		if (!strcmp(instruct, "pb\n"))
		{
			temp = stack_b;
			stack_b = ft_push_stack_checker(stack_b, stack_a);
			stack_a = temp;
		}
		free(instruct);
		instruct = get_next_line(std);
	}
	ft_printer(stack_a, stack_b);
	return (ft_stack_verificator(stack_a));
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	char	*instruct;
	int		verif;

	if (argc == 1)
		return (0);
	if (!argv_verificator(argv, argc))
		return (0);
	stack_a = ft_newstack(ft_atoi(argv[1]), 1, 'a');
	if (!stack_a_filler(argv, argc, stack_a))
		return (ft_free_stack(stack_a, NULL, 0));
	instruct = get_next_line(0);
	if (!ft_strcmp(instruct, "Error\n") && ft_stack_verificator(stack_a))
		return (0);
	verif = ft_checker(stack_a, instruct, 0);
	if (verif)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_stack(stack_a, NULL, 0);
	return (0);
}
