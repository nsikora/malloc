/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:55:39 by nsikora           #+#    #+#             */
/*   Updated: 2019/09/24 17:11:33 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct			s_header
{
	void				*array;
	size_t				header_nb;
}						t_header;

typedef struct			s_content
{
	void				*array;
	size_t				*size;
}						t_content;

typedef struct			s_page_management
{
	struct s_header		*header;
	struct s_content	*content;
	void 				*page;
	size_t				pagesize;
}						t_link;

void	*initialize_page(size_t size, struct s_page_management controller);
void    *write_memory(size_t size, struct s_page_management controller);
void    *malloc(size_t size);

#endif
