# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsikora <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 16:56:40 by nsikora           #+#    #+#              #
#    Updated: 2019/10/07 16:44:00 by nsikora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	malloc

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

INCLUDE	=	includes\malloc.h

SRCS	=	main.c \
			malloc.c \
			free.c

all: 		$(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) -o $(NAME) $(OBJS) -I . -L./libft -lft

%.o: %.c
	$(CC) -o $@ -c $< -I . $(CFLAGS)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re:	fclean all

.PHONY: all re clean fclean
