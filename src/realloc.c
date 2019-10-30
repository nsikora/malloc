/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/30 16:17:31 by nsikora          ###   ########.fr       */
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
	return (-1);
}

void		*realloc(void *ptr, size_t size)
{
	ft_putendl("appel a realloc");
	void	*str;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	if (pointer_finder(ptr, size) == 0)
		return (ptr);
	if ((str = malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(str, ptr, size);
	free(ptr);
	return (str);
}
