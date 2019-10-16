/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/16 16:46:03 by nsikora          ###   ########.fr       */
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
	if ((str = malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(str, ptr, size);
	return (str);
}
