/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:41:06 by ephoon            #+#    #+#             */
/*   Updated: 2024/05/16 18:12:10 by ephoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	stack_size(t_stack *stack)
{
	return (stack->size);
}

void	free_split_and_exit(char **split_args, t_stack *stack)
{
	free_split(split_args);
	error_exit_with_stack("Error", stack);
}

void	error_exit_with_stack(char *message, t_stack *stack)
{
	free_stack(stack);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	if (argc < 2 || (argc == 2 && ft_strlen(argv[1]) == 0))
	{
		error_exit("Error");
		return (1);
	}
	init_stack(&a);
	init_stack(&b);
	parse_args(argc, argv, &a);
	assign_indices(&a);
	if (stack_size(&a) > 5)
		radix_sort(&a, &b);
	else
		normal_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
