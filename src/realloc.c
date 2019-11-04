/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/11/04 12:52:59 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

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
	void	*str;

	if (!g_controller || !g_controller->bande || !ptr)
	{
		str = malloc(size);
		return (str);
	}
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (pointer_finder(ptr, size) == 0)
		return (ptr);
	if ((str = malloc(size)) == NULL)
		return (NULL);
	if (ft_strlen(str) > 0 && ft_strlen(ptr) > 0)
		ft_memcpy(str, ptr, size);
	free(ptr);
	return (str);
}
