/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/11/08 17:11:05 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"
#include <stdio.h>

char		expand_ptr(t_bande *bande, t_header *header, int n, size_t size)
{
	if (size * 100 > bande->size)
		return (-1);
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

	if (size <= 0)
	{
	 	free(ptr);
 		return (NULL);
 	}
	if (!g_controller || !g_controller->bande || !ptr)
	{
		str = malloc(size);
		return (str);
	}
	if ((size_malloc = pointer_finder(ptr, size)) == 0)
		return (ptr);
	if (!(str = malloc(size)))
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
