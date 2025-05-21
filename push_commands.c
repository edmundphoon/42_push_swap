/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:12:44 by ephoon            #+#    #+#             */
/*   Updated: 2024/05/16 17:29:30 by ephoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

t_node	*ft_stacknew(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_stackadd_back(t_stack *stack, t_node *new_node)
{
	t_node	*current;

	if (stack == NULL || new_node == NULL)
		return ;
	if (stack->top == NULL)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = ft_stacknew(value);
	if (!new_node)
		error_exit("Exit");
	ft_stackadd_back(stack, new_node);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	if (b->size == 0)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	b->size--;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	t_node	*tmp;

	if (a->size == 0)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	a->size--;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
	write(1, "pb\n", 3);
}
