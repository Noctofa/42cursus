# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:59:50 by sgaspard          #+#    #+#              #
#    Updated: 2023/05/24 21:39:14 by sgaspard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

INC = -Ilibft/ -Ipush_swap.h/

LIBFT = libft

LIBS = -Llibft -lft

SRCS = swap_operations.c rotate_operations.c reverse_rotate_operations.c \
			push_operations.c main.c check_functions.c push_swap.c \
			free.c simple_sort_functions.c utils.c create_stack.c

OBJS =	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME) : ${OBJS}
	$(MAKE) -sC $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

.c.o	:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean	:
	$(MAKE) -sC $(LIBFT) clean
	$(RM) $(OBJS)

fclean	:
	$(MAKE) -sC $(LIBFT) fclean
	$(RM) $(OBJS) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re