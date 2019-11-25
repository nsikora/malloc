/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:08:48 by nsikora           #+#    #+#             */
/*   Updated: 2019/11/25 11:09:13 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char    *(str[1024]);
	char	*(lel[100]);
	char	*test[100];
	char	*(ptr[4096]);

	int n = 0;
	while (n < 100)
	{
		str[n] = malloc(4096);
		//free(str[n]);
		//free(str[n]);
		test[n] = malloc(4096);
		lel[n] = malloc(8096);
		//free(lel[n]);
		//free(str[n]);
		//free(test[n]);
		free(lel[n]);
		test[n] = realloc(str[n], 0);
		//free(test[n]);
		//free(test[n]);
		n++;
    }
	n = 0;
	while (n < 100)
	{
		free(test[n]);
		n = n + 2;
	}
	n = 0;
	while (n < 50)
	{
		str[n] = malloc(2048);
		n++;
	}
	for (int n = 0 ; n < 100; n ++) {
		//free(str[n]);
		//free(str[n]);
		//test[n] = realloc(str[n], 80);
		//free(str[n]);
		//free(test[n]);
	}
	for (int n = 0 ; n < 5; n ++) {
		ptr[n] = malloc(getpagesize() * 101);
	}
	show_alloc_mem();
	return (0);
}
