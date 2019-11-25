/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/11/20 10:24:00 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

size_t		expand_ptr(t_bande *bande, t_header *header, int n, size_t size)
{
	if (size * 100 > bande->size)
		return (header[n].size);
	if ((((size_t)header[n].zone) < (size_t)header[n - 1].zone - size)
	|| (n == 0 && ((size_t)bande + bande->size > size)))
	{
		header[n].size = size;
		return (0);
	}
	return (header[n].size);
}

void		*realloc(void *ptr, size_t size)
{
	void	*str;
	size_t	size_malloc;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (size % 16 != 0)
		size = size + 16 - (size % 16);
	if (!g_controller || !g_controller->bande || !ptr)
		return (malloc(size));
	if ((size_malloc = pointer_finder(ptr, size)) == 0)
		return (ptr);
	if ((str = malloc(size)) == NULL)
		return (NULL);
	if (size_malloc < size)
		size = size_malloc;
	size_malloc = pointer_finder(str, size);
	if (size_malloc < size)
		size = size_malloc;
	ft_memcpy(str, ptr, size);
	free(ptr);
	return (str);
}
