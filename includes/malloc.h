/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:55:39 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/16 14:42:16 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include <unistd.h>

typedef struct				s_header
{
	void					*zone;
	size_t					size;
}							t_header;

typedef struct				s_bande_management
{
	size_t					size;
	void					*next;
}							t_bande_management;

typedef struct				s_page_management
{
	size_t					pagesize;
	void					*bande;
}							t_page_management;

void						show_alloc_mem(void);
void						*malloc(size_t size);
void						free(void *ptr);
void						*realloc(void *ptr, size_t size);

extern t_page_management	*g_controller;

#endif
