/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:49:01 by nsikora           #+#    #+#             */
/*   Updated: 2019/09/25 17:01:09 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"
#include <stdio.h>

t_page_management *g_controller = NULL;

char initialize_controller(void)
{
    if ((g_controller = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
        return (0);
    g_controller->bande = NULL;
    g_controller->pagesize = getpagesize();
    return (1);
}

size_t getHeaderPageSize(void)
{
    size_t size;

    size = sizeof(t_header) * 100;
    size = (size % g_controller->pagesize) ?
            size / g_controller->pagesize + 1 : size / g_controller->pagesize;
    return (size * g_controller->pagesize);
}

char							initialize_page(size_t size)
{
	size_t						tiny;
    size_t zone;
	size_t						small;
	size_t						large;

	tiny = getpagesize();
	small = tiny * 100;
	large = small * 100;
		
	if (size <= tiny)
        zone = (tiny * 100) + getHeaderPageSize();
	else if (size > tiny && size <= small)
        zone = (small * 100) + getHeaderPageSize();
	else
        zone = (large * 100) + getHeaderPageSize();
	if ((g_controller->bande = mmap(NULL, zone, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (0);
	g_controller->pagesize = zone;
	printf("%p, %p\n", g_controller->bande, g_controller->bande + zone);
	return (1);
}

void							*write_memory(size_t size)
{
    t_header *headers;
    size_t content_size;
    int n;

    if (!g_controller->bande)
        return (NULL);
    headers = (t_header *)g_controller->bande;
    n = 0;
    content_size = 0;
    while (headers[n].zone)
    {
        content_size += headers[n].size;
        n = n + 1;
    }
    headers[n].zone = g_controller->bande + (g_controller->pagesize - content_size - size);
    headers[n].size = size;

    return (headers[n].zone);
}

void							*ft_malloc(size_t size)
{
	char						*str;

	if (!g_controller && !initialize_controller())
        return (NULL);
	// check bande dispo
    if (!(initialize_page(size)))
		return (NULL);
	str =  write_memory(size);
	return (str);
}
