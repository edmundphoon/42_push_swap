/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:00:46 by ephoon            #+#    #+#             */
/*   Updated: 2024/05/16 18:10:11 by ephoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

void	parse_args(int argc, char **argv, t_stack *a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		split_and_process_args(argv[i], a);
		i++;
	}
	if (check_for_duplicate(a))
		error_exit_with_stack("Error", a);
}

void	split_and_process_args(char *arg, t_stack *a)
{
	char		**split_args;
	int			j;
	long		num;

	if (arg == NULL || ft_strlen(arg) == 0)
		error_exit_with_stack("Error", a);
	split_args = ft_split(arg, ' ');
	if (split_args == NULL || *split_args == NULL)
		free_split_and_exit(split_args, a);
	j = 0;
	while (split_args[j] != NULL)
	{
		if (!validate_integers(split_args[j]))
			free_split_and_exit(split_args, a);
		num = ft_atol(split_args[j]);
		if (num < INT_MIN || num > INT_MAX)
			free_split_and_exit(split_args, a);
		push(a, (int)num);
		free(split_args[j]);
		j++;
	}
	free(split_args);
}

void	assign_indices(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = a->top;
	while (current)
	{
		index = 0;
		compare = a->top;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

long	ft_atol(const char *nptr)
{
	long	num;
	int		negative;

	num = 0;
	negative = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			negative *= -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * negative);
}
