/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:59:59 by ephoon            #+#    #+#             */
/*   Updated: 2024/05/28 20:19:12 by ephoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	get_highest_bits(t_stack *a)
{
	int		max;
	int		bits;
	t_node	*current;

	max = a->top->index;
	bits = 0;
	current = a->top->next;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

int	count_nodes(t_stack *stack)
{
	int		count;
	t_node	*current;

	count = 0;
	current = stack->top;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		len_a;
	int		right_shift;
	int		j;

	if (is_sorted(a))
		return ;
	max_bits = get_highest_bits(a);
	right_shift = 0;
	while (right_shift < max_bits)
	{
		len_a = count_nodes(a);
		j = 0;
		while (j < len_a)
		{
			if (((a->top->index >> right_shift) & 1))
				ra(a);
			else
				pb(b, a);
			++j;
		}
		while (count_nodes(b) > 0)
			pa(a, b);
		++right_shift;
	}
}

void	normal_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}
