/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:49:01 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/22 15:56:29 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page *g_controller = NULL;

static char		initialize_controller(void)
{
	if ((g_controller = mmap(NULL, getpagesize(), PROT_READ
	| PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (0);
	g_controller->pagesize = getpagesize();
	g_controller->bande = NULL;
	return (1);
}

static void		*initialize_bande(size_t size)
{
	size_t		zone;
	t_bande		*bande;
	t_bande		*last_bande;

	zone = select_zone_size(size);
	if ((bande = mmap(NULL, zone, PROT_READ | PROT_WRITE, MAP_ANON
	| MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	if (!g_controller->bande)
		g_controller->bande = bande;
	else
	{
		last_bande = bande_retriever();
		last_bande->next = bande;
	}
	bande->size = zone;
	bande->next = NULL;
	return (bande);
}

static void		*write_memory(size_t size, void *bande)
{
	t_header	*headers;
	size_t		content_size;
	int			n;
	int			spacing;

	headers = ((t_header *)(bande) + sizeof(t_bande));
	n = 0;
	spacing = 0;
	content_size = 0;
	while (headers[n].zone)
	{
		content_size += headers[n].size;
		n = n + 1;
	}
	if (headers[n - 1].zone == bande + (((t_bande *)bande)->size
	- content_size - size - spacing))
		spacing = spacing + size;
	headers[n].zone = bande + (((t_bande *)bande)->size
	- content_size - size - spacing);
	headers[n].size = size;
	return (headers[n].zone);
}

static void		*bande_checker(size_t size)
{
	void		*bande;
	t_header	*header;
	int			n;

	bande = g_controller->bande;
	while (bande)
	{
		header = ((t_header *)(bande) + sizeof(t_bande));
		n = 0;
		while (header[n].zone)
			n = n + 1;
		if (header[n - 1].zone - (void *)(header + n + 1) - sizeof(t_header)
		>= size && size * 100 <= ((t_bande *)bande)->size)
			return (bande);
		bande = ((t_bande *)bande)->next;
	}
	return (NULL);
}

void			*malloc(size_t size)
{
	char		*str;
	void		*bande;

	if (!g_controller && !initialize_controller())
		return (NULL);
	if ((bande = bande_checker(size)))
		return (write_memory(size, bande));
	if (!(bande = initialize_bande(size)))
		return (NULL);
	str = write_memory(size, bande);
	return (str);
}
