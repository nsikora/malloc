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

void            	free_memory(t_header *header)
{
    t_header		*last;
    int				n;

    last = header;
    n = 0;
    while (last[n].zone) {
        n = n + 1;
    }

    if (last + n != header)
    {
        ft_memmove(header, header + 1, (last + n) - (header + 1));
        last[n - 1].zone = NULL;
        last[n - 1].size = 0;
    }
}

void            	pointer_finder(void *ptr)
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
}

void            	free(void *ptr)
{
    if (!g_controller || !g_controller->bande || !ptr)
        return ;
    pointer_finder(ptr);
}
