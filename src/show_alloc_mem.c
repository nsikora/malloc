/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:25:18 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/15 15:37:41 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"
#include "libft/libft.h"
#include <stdio.h>

void			display_bande(void *bande)
{
	if (((t_bande_management *)bande)->size <=  g_controller->pagesize * 101)
		ft_putstr("TINY : ");
	else if (((t_bande_management *)bande)->size >  g_controller->pagesize * 101
	&& ((t_bande_management *)bande)->size <=  g_controller->pagesize * 10001)
		ft_putstr("SMALL : ");
	else
		ft_putstr("LARGE : ");
	printf("%p\n", bande);
}

void			show_alloc_mem(void)
{
	void		*bande;
	t_header	*header;
	int		n;

	if (!g_controller || !g_controller->bande)
		return ;
	bande = g_controller->bande;
	while (bande)
	{
		header = ((t_header *)(bande) + sizeof(t_bande_management));
		display_bande(bande);
		n = 0;
		while (header[n].zone)
		{
			n++;
		}
		n--;
		while (n >= 0)
		{
			printf("%p - %p : %zu bytes\n", header[n].zone, header[n].zone + header[n].size - 1, header[n].size);
			n--;
		}
		bande = ((t_bande_management *)bande)->next;
	}
}
