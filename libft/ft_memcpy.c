/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 13:48:12 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/16 15:02:48 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dst;
	unsigned char	*c_src;

	i = 0;
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
