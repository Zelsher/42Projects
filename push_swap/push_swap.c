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

int	ft_stack_atoi(const char *str, int *test)
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
		stack_a->next = ft_newstack(ft_stack_atoi(argv[i], test), i, 'a');
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

t_stack	*ft_one_string_arg(char *str, int *test)
{
	size_t	i;
	t_stack	*stack_a;
	t_stack	*temp;
	char	**arguments;

	i = 0;
	while (ft_isdigit(str[i]) || str[i] == ' ')
		i++;
	if (str[i] && (!ft_isdigit(str[i]) || str[i] == ' '))
		return (NULL);
	arguments = ft_split(str, ' ');
	stack_a = ft_newstack(ft_stack_atoi(arguments[0], test), 1, 'a');
	temp = stack_a;
	i = 1;
	while (arguments[i])
	{
		stack_a->next = ft_newstack(ft_stack_atoi(arguments[i], test), i + 1, 'a');
		stack_a = stack_a->next;
		i++;
	}
	ft_free_double_tab(arguments);
	return (temp);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*temp;
	int		test;

	test = 0;
	ft_printf("argc : %d, argv1 : %s\n", argc, argv[1]);
	if (argc == 2)
	{
		stack_a = ft_one_string_arg(argv[1], &test);
		temp = ft_one_string_arg(argv[1], &test);
		if (!stack_a)
			return (ft_free_stack(stack_a, temp, 1));
	}
	else
	{
		if (!argv_verificator(argv, argc))
			return (0);
		stack_a = ft_newstack(ft_stack_atoi(argv[1], &test), 1, 'a');
		temp = ft_newstack(ft_stack_atoi(argv[1], &test), 1, 'a');
		if (!stack_a_filler(argv, argc, stack_a, &test))
			return (ft_free_stack(stack_a, temp, 1));
		if (!stack_a_filler(argv, argc, temp, &test))
			return (ft_free_stack(stack_a, temp, 1));
	}
	ft_radix(stack_a, temp);
	return (0);
}
