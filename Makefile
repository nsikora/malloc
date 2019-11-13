# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsikora <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 16:56:40 by nsikora           #+#    #+#              #
#    Updated: 2019/11/13 15:12:04 by nsikora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		=	libft_malloc_$(HOSTTYPE).so
NAMELN		=	libft_malloc.so

CC			=	/usr/bin/gcc

CFLAGS		=	-Wall -Wextra -Werror -fPIC

OBJS    	=	$(addprefix $(SRCDIRS)/, $(SRCS:.c=.o))

RM			=	/bin/rm -f

LN			=	ln -fs

SRCDIRS		=	src

SRCS		=	malloc.c			\
				malloc_utils.c		\
				free.c				\
				realloc.c			\
				show_alloc_mem.c

INCLUDE		=	-I includes -I libft

LIBFT		=	libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS) $(INCLUDE) -L ./libft -lft
	$(LN) $(NAME) $(NAMELN)

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
