/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:37:37 by ephoon            #+#    #+#             */
/*   Updated: 2024/02/16 17:29:43 by ephoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
}	t_stack;

//Swap commands
void			swap(t_stack *stack);
void			sa(t_stack *a);
void			sb(t_stack *b);
void			ss(t_stack *a, t_stack *b);

//Push commands
void			push(t_stack *stack, int value);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *b, t_stack *a);

//Rotate commands
void			rotate(t_stack *stack);
void			ra(t_stack *a);
void			rb(t_stack *b);
void			rr(t_stack *a, t_stack *b);

//Reverse rotate commands
void			reverse_rotate(t_stack *stack);
void			rra(t_stack *a);
void			rrb(t_stack *b);
void			rrr(t_stack *a, t_stack *b);

//Utilities
void			init_stack(t_stack *stack);
void			parse_args(int argc, char **argv, t_stack *a);
void			split_and_process_args(char *arg, t_stack *a);
void			radix_sort(t_stack *a, t_stack *b);
void			normal_sort(t_stack *a, t_stack *b);
bool			is_sorted(t_stack *stack);
void			sort_three(t_stack *a);
void			sort_four(t_stack *a, t_stack *b);
void			sort_five(t_stack *a, t_stack *b);
void			assign_indices(t_stack *a);
long			ft_atol(const char *nptr);
int				count_nodes(t_stack *stack);

//Error handling
int				validate_integers(const char *str);
int				check_for_duplicate(t_stack *stack);
void			free_stack(t_stack *stack);
void			free_split(char **split_args);
void			error_exit(char *message);
void			error_exit_with_stack(char *message, t_stack *stack);
void			free_split_and_exit(char **split_args, t_stack *stack);

//Libft functions
char			**ft_split(char const *s, char c);
size_t			ft_strlen(char *str);
int				ft_isdigit(int ch);
int				ft_strncmp(char *s1, char *s2, unsigned int n);

#endif
