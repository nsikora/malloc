/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/18 16:23:54 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"
#include <stdio.h>

char		expand_ptr(t_bande_management *bande, t_header *header, int n, size_t size)
{
	if (size * 100 > bande->size)
		return (-1);
	if ((header[n].zone
	&& ((size_t)header[n].zone) < (size_t)header[n - 1].zone - size + 1)
	|| (n == 0
	&& (size_t)bande + bande->size > (size_t)header[n].zone - size + 1))
	{
		ft_putendl("expand to next header");
		printf("%d, %p, %p\n", n, header[n].zone, header[n].zone + size  - 1);
		header[n].size = size;
		return (0);
	}
	printf("%d, %p, %p\n", n, header[n + 1].zone, header[n].zone);
	ft_putendl("error");
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
	printf("free is occuring \n");
	free(ptr);
	return (str);
}
