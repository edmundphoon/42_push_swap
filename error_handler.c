/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:55:22 by ephoon            #+#    #+#             */
/*   Updated: 2024/05/16 17:57:15 by ephoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int	validate_integers(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_for_duplicate(t_stack *stack)
{
	t_node	*current;
	t_node	*i;

	current = stack->top;
	while (current)
	{
		i = current->next;
		while (i)
		{
			if (i->value == current->value)
				return (1);
			i = i->next;
		}
		current = current->next;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (stack == NULL)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	stack->top = NULL;
	stack->size = 0;
}

void	free_split(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i] != NULL)
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	error_exit(char *message)
{
	write (2, message, ft_strlen(message));
	write (2, "\n", 1);
	exit(EXIT_FAILURE);
}
