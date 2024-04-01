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

#include "../inc/push_swap.h"

int	stack_atoi(const char *str, int *test)
{
	long long int	result;
	int				i;
	int				minus;

	i = 0;
	result = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if ((int)result * minus <= -2147483647)
		*test = 1;
	return (result * minus);
}

t_stack	*ft_one_string_arg(char *str, int *test, char **arguments, size_t i)
{
	t_stack	*stack_a;
	t_stack	*temp;

	while (ft_isdigit(str[i]) || str[i] == ' '
		|| str[i] == '-' || str[i] == '+')
		i++;
	if (str[i])
		return (NULL);
	arguments = ft_split(str, ' ');
	stack_a = ft_newstack(stack_atoi(arguments[0], test), 1, 'a');
	if (!stack_a)
		return (NULL);
	temp = stack_a;
	i = 1;
	while (arguments[i] && stack_a)
	{
		stack_a->next = ft_newstack(stack_atoi(arguments[i], test), i + 1, 'a');
		stack_a = stack_a->next;
		i++;
	}
	ft_free_double_tab(arguments);
	if (!stack_a)
		ft_free_stack(temp, NULL, 1);
	return (temp);
}

t_stack	*stack_a_filler(char **argv, int argc, t_stack *stack_a, int *test)
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
		stack_a->next = ft_newstack(stack_atoi(argv[i], test), i, 'a');
		if (!stack_a->next)
			return (NULL);
		stack_a = stack_a->next;
		next = temp;
		while (next != stack_a)
		{
			if (stack_a->num == next->num || *test == 1)
				return (NULL);
			next = next->next;
		}
	}
	return (temp);
}

int	push_swap(int argc, char **argv, t_stack *stack_a, t_stack *temp)
{
	int		test;

	test = 0;
	if (argc == 2)
	{
		stack_a = ft_one_string_arg(argv[1], &test, NULL, 0);
		temp = ft_one_string_arg(argv[1], &test, NULL, 0);
		if (!stack_a || !temp)
			return (ft_free_stack(stack_a, temp, 1), 0);
	}
	else
	{
		stack_a = ft_newstack(stack_atoi(argv[1], &test), 1, 'a');
		temp = ft_newstack(stack_atoi(argv[1], &test), 1, 'a');
		if (!stack_a || !temp)
			return (ft_free_stack(stack_a, temp, 1), 1);
		if (!stack_a_filler(argv, argc, stack_a, &test))
			return (ft_free_stack(stack_a, temp, 1), 1);
		if (!stack_a_filler(argv, argc, temp, &test))
			return (ft_free_stack(stack_a, temp, 1), 1);
	}
	ft_radix(stack_a, temp, 1, 0);
	return (0);
}
