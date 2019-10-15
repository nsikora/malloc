/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:25:35 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/14 11:34:25 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/malloc.h"
#include <stdio.h>

static char            	free_memory(t_header *header)
{
    t_header		*last;
    int				n;

    last = header;
    n = 0;
//    printf("A - %p\n", header[0].zone);
    while (last[n].zone) {
        if (n > 0)
        {
            last[n - 1].zone = last[n].zone;
            last[n - 1].size = last[n].size;
        }
//        printf("%p\n", last[n].zone);
        n = n + 1;
    }
//    printf("B - %p\n", header[0].zone);

//    if (last + n != header)
//        ft_memmove(header, header + 1, (last + n) - (header + 1));
    if (n > 0)
        n = n - 1;
    last[n].zone = NULL;
    last[n].size = 0;

//    printf("%d\n", n);
    return (0);
}

static char                 ft_bande_liberator(void *ptr)
{
    t_bande_management  *management;
    t_bande_management  *tmp;

    management = (t_bande_management *)ptr;
//    printf("Munmap %p\n", ptr);

    tmp = g_controller->bande;
    if (tmp == ptr)
        g_controller->bande = ((t_bande_management *)ptr)->next;
    else
    {
        while (tmp->next != ptr)
            tmp = tmp->next;
        tmp->next = ((t_bande_management *)ptr)->next;
    }

    return ((char)munmap(ptr, management->size));
}

static char                ft_bande_checker(void)
{
    unsigned int        n;
    void    			*bande;
    t_header		    *header;
    void                *ptr;

    bande = g_controller->bande;

    n = 0;
    ptr = NULL;
    while (bande)
    {
        header = ((t_header *)(bande) + sizeof(t_bande_management));
//        printf("%p\n", (*header).zone);
        if (!(*header).zone)
        {
            ptr = bande;
            n = n + 1;
        }

        bande = ((t_bande_management *)bande)->next;
    }

//    printf("%u\n", n);
    if (n > 1)
        return (ft_bande_liberator(ptr));
    return (0);
}

static char            	pointer_finder(void *ptr)
{
    void			*bande;
	int				n;
    t_header		*header;

    bande = g_controller->bande;

    while (bande)
    {
        header = ((t_header *)(bande) + sizeof(t_bande_management));

        n = 0;
        while (header[n].zone)
        {
            if (header[n].zone == ptr)
                return free_memory(header + n);
            n = n + 1;
        }
        bande = ((t_bande_management *)bande)->next;
    }

//    printf("--- %p\n\n", ptr);
//    printf("ERROR\n");
    return (-1);
}

char            	ft_free(void *ptr)
{
    if (!g_controller || !g_controller->bande || !ptr)
        return (-1);
//    printf("free %p...\n", ptr);
    if (pointer_finder(ptr) == -1)
        return (-1);
//    printf("Checker\n");
    return (ft_bande_checker());
}
