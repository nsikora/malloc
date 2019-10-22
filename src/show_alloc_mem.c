/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:25:18 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/22 16:11:59 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "libft.h"

static void		display_address(size_t address_nb)
{
	size_t		value;
	size_t		divider;

	ft_putstr("0x");
	divider = 1;
	while (divider < address_nb / 16)
		divider = divider * 16;
	while (divider >= 1)
	{
		value = address_nb / divider;
		address_nb = address_nb % divider;
		divider = divider / 16;
		if (value < 10)
			ft_putchar('0' + value);
		else
			ft_putchar('a' + value - 10);
	}
}

static void		display_bande(void *bande)
{
	size_t		bande_size;

	bande_size = ((t_bande *)bande)->size;
	if (bande_size == g_controller->pagesize * 101)
		ft_putstr("TINY : ");
	else if (bande_size == g_controller->pagesize * 10001)
		ft_putstr("SMALL : ");
	else
		ft_putstr("LARGE : ");
	display_address((size_t)bande);
	ft_putchar('\n');
}

static size_t	print_mem(t_header *header, int n, size_t total)
{
	display_address((size_t)header[n].zone);
	ft_putstr(" - ");
	display_address((size_t)header[n].zone + header[n].size - 1);
	ft_putstr(" : ");
	ft_putnbr(header[n].size);
	ft_putendl(" byte(s)");
	total = total + header[n].size;
	return (total);
}

static void		print_total(size_t total)
{
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putendl(" byte(s)");
}

void			show_alloc_mem(void)
{
	void		*bande;
	t_header	*header;
	int			n;
	size_t		total;

	if (!g_controller || !g_controller->bande)
		return ;
	total = 0;
	bande = g_controller->bande;
	while (bande)
	{
		header = ((t_header *)(bande) + sizeof(t_bande));
		display_bande(bande);
		n = 0;
		while (header[n].zone)
			n++;
		n--;
		while (n >= 0)
		{
			total = print_mem(header, n, total);
			n--;
		}
		bande = ((t_bande *)bande)->next;
	}
	print_total(total);
}
