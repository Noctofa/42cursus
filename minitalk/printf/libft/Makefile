# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaspard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 11:38:20 by sgaspard          #+#    #+#              #
#    Updated: 2023/02/13 15:28:24 by sgaspard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
INCLUDE = ../includes
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I 
AR = ar rcs

SOURCES = ft_bzero ft_isalnum ft_isalpha \
		ft_isascii ft_isdigit ft_isprint \
		ft_memchr ft_memcmp ft_memcpy \
		ft_memmove ft_memset ft_strchr \
		ft_strlcat ft_strlcpy ft_strlen \
		ft_strncmp ft_strnstr ft_strrchr \
		ft_tolower ft_toupper ft_atoi \
		ft_strdup ft_calloc ft_substr \
		ft_strjoin ft_strtrim ft_split \
		ft_itoa ft_strmapi ft_striteri \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd \
		ft_putnbr_fd ft_atoi

SRCS = $(addsuffix .c, $(SOURCES))
OBJS = $(addsuffix .o, $(SOURCES))

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
