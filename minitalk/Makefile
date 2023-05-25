# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 16:24:05 by sgaspard          #+#    #+#              #
#    Updated: 2023/05/24 21:14:04 by sgaspard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
INCLUDE = -I minitalk.h
PRINTF = printf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

SOURCEC = client
SOURCES = server

SRCSS = $(addsuffix .c, $(SOURCES))
OBJSS = $(addsuffix .o, $(SOURCES))

SRCSC = $(addsuffix .c, $(SOURCEC))
OBJSC = $(addsuffix .o, $(SOURCEC))

all : $(NAMEC) $(NAMES)

$(NAMEC) : $(OBJSC)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) $(PRINTF)/libftprintf.a $(INCLUDE) -o $(NAMEC) $(SRCSC)

$(NAMES) : $(OBJSS)
	$(CC) $(CFLAGS) $(PRINTF)/libftprintf.a $(INCLUDE) -o $(NAMES) $(SRCSS)


clean : 
	$(RM) -r $(OBJSC)
	$(RM) -r $(OBJSS)
	make clean -C $(PRINTF)


fclean : clean
	$(RM) $(NAMEC)
	$(RM) $(NAMES)
	make fclean -C $(PRINTF)


re : fclean all


.PHONY : all clean fclean re
