/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:49:01 by nsikora           #+#    #+#             */
/*   Updated: 2019/09/23 10:57:46 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*initialize_page(size_t page_size)
{
	void 	*str;

	if (size <= TINY)
	{
		if ((str = mmap(NULL, TINY * 100, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (NULL);
	}
	if (size > TINY && size <= SMALL)
	{
		if ((str = mmap(NULL, SMALL * 100, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (NULL);
	}
	if (size > SMALL) {
		if ((str = mmap(NULL, SMALL * 10000, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (NULL);
	}
	return (str);
}

void		*malloc(size_t size)
{
	size_t	page_size;
	void	*str;

	if ((page_size = (size_t)getpagesize()) <= 0)
		return (str);
	if (page_size < size)
	{
		if ((str = initialize_page(page_size)) == NULL)
			return (NULL);
		while (page_size < size)
		{
			size = size - page_size;
			expand_page(size, page_size, *str)
		}
	}
	else
	{
		if ((str = initialize_page(size)) == NULL)
			return (NULL);
	}
	return (str);
}

void		*expand_page(size_t size, size_t page_size, void *str)
{
	return (str);
}
