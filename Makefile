# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlarioui <mlarioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:54:02 by mlarioui          #+#    #+#              #
#    Updated: 2024/10/04 21:50:25 by mlarioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = printing.c ft_printf.c puthexnbr.c

OBJS = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror  

AR = ar rcs
INCLUDE = libftprintf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)  

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re