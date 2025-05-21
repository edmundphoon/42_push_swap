/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:12:29 by ephoon            #+#    #+#             */
/*   Updated: 2024/05/28 15:22:12 by ephoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa (a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa (a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	while (a->top->index != 0)
		ra(a);
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->top->index != 0 && a->top->index != 1)
		ra(a);
	pb(b, a);
	while (a->top->index != 0 && a->top->index != 1)
		ra(a);
	pb(b, a);
	sort_three(a);
	if (b->top->index < b->top->next->index)
		sb(b);
	pa(a, b);
	pa(a, b);
}
