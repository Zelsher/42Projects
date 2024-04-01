/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:17:34 by eboumaza          #+#    #+#             */
/*   Updated: 2023/11/22 10:17:36 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				place;
	int				max_digit;
	char			stack;
	struct s_stack	*next;
}					t_stack;

int			ft_printer(t_stack *stack_a, t_stack *stack_b);

void		ft_radix(t_stack *stack_a, t_stack *temp, size_t i, size_t y);
void		ft_easy_solver(t_stack *stack_a, t_stack *temp, int argc);

int			ft_digit_counter(int digit);
t_stack		*ft_resolver(t_stack *stack_a, t_stack *current);

void		ft_free_stack(t_stack *stack_a, t_stack *temp, int test);
t_stack		*ft_newstack(int content, int place, char c);

t_stack		*ft_rotate_stack(t_stack *stack_a, char c);
t_stack		*ft_push_stack(t_stack *stack_a, t_stack *stack_b, char c);
t_stack		*ft_swap_stack(t_stack *stack_a, char c);

int			argv_verificator(char **argv, int argc);
int			stack_atoi(const char *str, int *test);
t_stack		*ft_one_string_arg(char *str, int *test, char **argum, size_t i);
t_stack		*stack_a_filler(char **argv, int argc, t_stack *stack_a, int *test);

int			push_swap(int argc, char **argv, t_stack *stack_a, t_stack *temp);

#endif