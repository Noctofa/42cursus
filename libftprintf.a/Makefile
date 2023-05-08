# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:36:30 by sgaspard          #+#    #+#              #
#    Updated: 2023/02/13 12:53:31 by sgaspard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = includes
LIBFT = libft
SRCS_DIR = srcs/
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I
RM = rm -f
AR = ar rcs

SOURCES = ft_printf ft_print_utili ft_print_hexa \
		  ft_print_ptr ft_print_unsignednb

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SOURCES)))
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(SOURCES)))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	mv *.o $(SRCS_DIR)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

$(SRCS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $?

clean : 
	$(RM) -r $(NAME)
	$(RM) -r $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re : fclean all

.PHONY : all clean fclean re
