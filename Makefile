# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ephoon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:22:30 by ephoon            #+#    #+#              #
#    Updated: 2024/05/28 20:07:09 by ephoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			cc
CFLAGS = 		-Wall -Wextra -Werror -g
NAME =			push_swap
LIBFT =			./libft/libft.a

SRCS =			push_swap.c \
				error_handler.c \
				push_commands.c \
				rotate_commands.c \
				reverse_rotate_commands.c \
				swap_commands.c \
				push_swap_utils.c \
				sort_handler.c \
				simple_sort.c

OBJS =			$(SRCS:.c=.o)

all:			$(NAME)

$(NAME): $(OBJS)
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
