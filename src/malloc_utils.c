/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:47:49 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/18 17:01:47 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t					get_header_page_size(int header_nb)
{
	size_t				size;

	size = sizeof(t_header) * header_nb + sizeof(t_bande_management);
	size = (size % g_controller->pagesize) ?
	size / g_controller->pagesize + 1 : size / g_controller->pagesize;
	return (size * g_controller->pagesize);
}

void					*bande_retriever(void)
{
	t_bande_management	*bande;

	bande = g_controller->bande;
	while (bande->next)
		bande = bande->next;
	return (bande);
}

size_t					select_zone_size(size_t size)
{
	size_t				tiny;
	size_t				small;
	size_t				zone;

	tiny = getpagesize();
	small = tiny * 100;
	if (size <= tiny)
		zone = (tiny * 100) + get_header_page_size(100);
	else if (size > tiny && size <= small)
		zone = (small * 100) + get_header_page_size(100);
	else
		zone = size + get_header_page_size(1);
	return (zone);
}
