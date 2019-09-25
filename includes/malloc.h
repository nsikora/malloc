/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:55:39 by nsikora           #+#    #+#             */
/*   Updated: 2019/09/25 17:01:03 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>

typedef struct			s_header
{
	void				*zone;
	size_t				size;
}						t_header;

typedef struct			s_page_management
{
	void 				*bande;
	size_t				pagesize;
}						t_page_management;

char	initialize_page(size_t size);
void    *write_memory(size_t size);
void    *ft_malloc(size_t size);

extern t_page_management *g_controller;

#endif
