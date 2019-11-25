/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:25:35 by nsikora           #+#    #+#             */
/*   Updated: 2019/11/19 13:59:12 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

static size_t		free_memory(t_header *header)
{
	int		n;

	n = 0;
	while (header[n].zone)
	{
		if (n > 0)
		{
			header[n - 1].zone = header[n].zone;
			header[n - 1].size = header[n].size;
		}
		n = n + 1;
	}
	if (n > 0)
		n = n - 1;
	header[n].zone = NULL;
	header[n].size = 0;
	return (1);
}

static void			ft_bande_liberator(void *ptr)
{
	t_bande			*management;
	t_bande			*tmp;

	management = (t_bande *)ptr;
	tmp = g_controller->bande;
	if (tmp == ptr)
		g_controller->bande = ((t_bande *)ptr)->next;
	else
	{
		while (tmp->next != ptr)
			tmp = tmp->next;
		tmp->next = ((t_bande *)ptr)->next;
	}
	munmap(ptr, management->size);
}

static void			ft_bande_checker(void)
{
	unsigned int	n;
	void			*bande;
	t_header		*header;
	void			*ptr;

	bande = g_controller->bande;
	n = 0;
	ptr = NULL;
	while (bande)
	{
		header = ((t_header *)(bande) + sizeof(t_bande));
		if (!(*header).zone)
		{
			ptr = bande;
			n = n + 1;
		}
		bande = ((t_bande *)bande)->next;
	}
	if (n > 1)
		ft_bande_liberator(ptr);
}

size_t				pointer_finder(void *ptr, size_t size)
{
	void			*bande;
	int				n;
	t_header		*header;

	bande = g_controller->bande;
	while (bande)
	{
		header = ((t_header *)(bande) + sizeof(t_bande));
		n = 0;
		while (header[n].zone)
		{
			if (header[n].zone == ptr && size == 0)
				return (free_memory(header + n));
			if (header[n].zone == ptr && size > 0)
				return (expand_ptr((t_bande *)bande, header, n, size));
			n++;
		}
		bande = ((t_bande *)bande)->next;
	}
	return (0);
}

void				free(void *ptr)
{
	if (!g_controller || !g_controller->bande || !ptr)
		return ;
	if (pointer_finder(ptr, 0) == 1)
		ft_bande_checker();
}
