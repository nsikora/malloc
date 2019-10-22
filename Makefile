# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsikora <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 16:56:40 by nsikora           #+#    #+#              #
#    Updated: 2019/10/22 13:33:25 by nsikora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	malloc

CC	=	/usr/bin/gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJS    =	$(addprefix $(SRCDIRS)/, $(SRCS:.c=.o))

RM	=	/bin/rm -f

SRCDIRS	=	src

SRCS	=	main.c				\
			malloc.c			\
			malloc_utils.c		\
			free.c				\
			realloc.c			\
			show_alloc_mem.c	\

INCLUDE	=	-I includes -I libft

LIBFT	=	libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(INCLUDE) -L ./libft -lft

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -o $@ -c $< -I . $(INCLUDE) $(CFLAGS)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re:	fclean all

.PHONY: all re clean fclean
