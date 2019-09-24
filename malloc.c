/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:49:01 by nsikora           #+#    #+#             */
/*   Updated: 2019/09/24 17:11:31 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"

void							*initialize_page(size_t size, struct s_page_management controller)
{
	size_t						tiny;
	size_t						small;
	size_t						large;

	tiny = getpagesize();
	small = tiny * 100;
	large = small * 100;
		
	if (size <= tiny)
		controller.pagesize = tiny;
	if (size > tiny && size <= small)
		controller.pagesize = small;
	if (size > small)
		controller.pagesize = large;
	if ((controller.page = mmap(NULL, controller.pagesize, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	return (controller.page);
}

void							*write_memory(size_t size, struct s_page_management controller)
{
	size = size + 1;
	return (controller.content[0].array);
}

void							*malloc(size_t size)
{
	char						*str;
	struct	s_page_management	controller;
	
	controller.header = NULL;
	controller.content = NULL;
	if ((controller.page = initialize_page(size, controller)) == NULL)
		return (NULL);
	str =  write_memory(size, controller);
	return (str);
}
