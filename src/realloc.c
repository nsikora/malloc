/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:11:55 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/16 15:45:23 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

void		*realloc(void *ptr, size_t size)
{
	void	*str;

	if (!g_controller || size <= 0)
		return (NULL);
	if (ptr == NULL)
		return (malloc(size));
	if ((str = malloc(size)) == NULL)
		return (NULL);
	ft_memcpy(str, ptr, size);
	return (str);
}
