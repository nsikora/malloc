/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:55:39 by nsikora           #+#    #+#             */
/*   Updated: 2019/09/19 15:15:25 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include "libft/libft.h"

# define TINY 4096
# define SMALL 40960

typedef struct s_rlimit
{
	size_t		cur;
	size_t		max;
}				t_rlimit;

typedef struct s_link
{
	void		*end;
	void		*next;
}				t_link;

void	*initialize_page(size_t page_size);
void    *malloc(size_t size);
void	*expand_page(size_t size, size_t page_size, void *str);

#endif
