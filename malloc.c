/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:49:01 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/07 16:02:19 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"
#include <stdio.h>

t_page_management *g_controller = NULL;

char					initialize_controller(void)
{
    if ((g_controller = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
        return (0);
    g_controller->pagesize = getpagesize();
    g_controller->bande = NULL;
    return (1);
}

size_t					getHeaderPageSize(void)
{
    size_t				size;

    size = sizeof(t_header) * 100 + sizeof(t_bande_management);
    size = (size % g_controller->pagesize) ?
            size / g_controller->pagesize + 1 : size / g_controller->pagesize;
    return (size * g_controller->pagesize);
}

void					*bande_retriever(void)
{
    t_bande_management *bande = g_controller->bande;

    while (bande->next)
        bande = bande->next;
    return (bande);
}

void					*initialize_bande(size_t size)
{
	size_t				tiny;
    size_t				zone;
	size_t				small;
	size_t				large;
	t_bande_management	*bande;
	t_bande_management	*last_bande;

	tiny = getpagesize();
	small = tiny * 100;
	large = small * 100;
		
	if (size <= tiny)
        zone = (tiny * 100) + getHeaderPageSize();
	else if (size > tiny && size <= small)
        zone = (small * 100) + getHeaderPageSize();
	else
        zone = (large * 100) + getHeaderPageSize();
	if ((bande = mmap(NULL, zone, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
//    printf("Mmap %p\n", (void *)bande);
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

void					*write_memory(size_t size, void *bande)
{
    t_header			*headers;
    size_t				content_size;
    int					n;

    headers = ((t_header *)(bande) + sizeof(t_bande_management));
    n = 0;
    content_size = 0;
    while (headers[n].zone)
    {
        content_size += headers[n].size;
        n = n + 1;
    }
    headers[n].zone = bande + (((t_bande_management *)bande)->size - content_size - size);
    headers[n].size = size;

    return (headers[n].zone);
}

void					*ft_bande_checker(size_t size)
{
    void				*bande;
    t_header			*header;
    int					n;

    bande = g_controller->bande;
    while (bande) {

        header = ((t_header *)(bande) + sizeof(t_bande_management));

        n = 0;
        while (header[n].zone)
            n = n + 1;

        if (header[n - 1].zone - (void *)(header + n + 1) - sizeof(t_header) >= size)
            return (bande);

        bande = ((t_bande_management *)bande)->next;
    }
    return (NULL);
}

void					*ft_malloc(size_t size)
{
	char				*str;
	void				*bande;

	if (!g_controller && !initialize_controller())
        return (NULL);
	if ((bande = ft_bande_checker(size)))
        return (write_memory(size, bande));
    if (!(bande = initialize_bande(size)))
		return (NULL);
    str =  write_memory(size, bande);
	return (str);
}
