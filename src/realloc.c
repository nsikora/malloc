/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/18 12:44:38 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

void		*reallocf(void *ptr, size_t size)
{
	char	*str;

	str = realloc(ptr, size);
	free(ptr);
	return (str);
}

char		expand_ptr(t_bande_management *bande, t_header *header, int n, size_t size)
{
	if (!header[n + 1].zone && ((size_t)header[n].zone + size) <= ((size_t)bande + bande->size))
	{
		header[n].size = size;
		return (0);
	}
	else if (header[n + 1].zone && ((size_t)header[n].zone + size) < (size_t)header[n + 1].zone)
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
		return ptr;
	if ((str = malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(str, ptr, size);
	free(ptr);
	return (str);
}
