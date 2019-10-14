/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:55:39 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/14 11:34:31 by nsikora          ###   ########.fr       */
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

typedef struct          s_bande_management
{
    size_t              size;
    void                *next;
}                       t_bande_management;

typedef struct			s_page_management
{
    size_t				pagesize;
	void 				*bande;
}						t_page_management;

void	*initialize_bande(size_t size);
void    *write_memory(size_t size, void *bande);
void    *ft_malloc(size_t size);
void	free(void *ptr);

extern t_page_management *g_controller;

#endif
