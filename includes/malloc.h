/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:55:39 by nsikora           #+#    #+#             */
/*   Updated: 2019/11/18 12:06:10 by nsikora          ###   ########.fr       */
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

typedef struct				s_bande
{
	size_t					size;
	void					*next;
}							t_bande;

typedef struct				s_page
{
	size_t					pagesize;
	void					*bande;
}							t_page;

void						show_alloc_mem(void);
void						*malloc(size_t size);
void						free(void *ptr);
void						*realloc(void *ptr, size_t size);
size_t						pointer_finder(void *ptr, size_t size);
size_t						expand_ptr(t_bande *bande, t_header *header,
							int n, size_t size);
size_t						get_header_page_size(int header_nb);
void						*bande_retriever(void);
size_t						select_zone_size(size_t size);

extern t_page				*g_controller;

#endif
