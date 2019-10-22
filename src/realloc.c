/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/22 15:13:33 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

char		expand_ptr(t_bande *bande, t_header *header, int n, size_t size)
{
	if (size * 100 > bande->size)
		return (-1);
	if ((header[n].zone
	&& ((size_t)header[n].zone) < (size_t)header[n - 1].zone - size + 1)
	|| (n == 0
	&& (size_t)bande + bande->size > (size_t)header[n].zone - size + 1))
	{
		header[n].size = size;
		return (0);
	}
	return (-1);
}

void		*realloc(void *ptr, size_t size)
{
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
