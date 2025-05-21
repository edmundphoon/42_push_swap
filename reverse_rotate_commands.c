/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:46:43 by ephoon            #+#    #+#             */
/*   Updated: 2024/05/16 17:51:48 by ephoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*previous;

	if (stack->size < 2)
		return ;
	current = stack->top;
	previous = NULL;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	if (previous)
		previous->next = NULL;
	current->next = stack->top;
	stack->top = current;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
