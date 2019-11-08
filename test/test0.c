/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:08:48 by nsikora           #+#    #+#             */
/*   Updated: 2019/11/08 14:38:15 by nsikora          ###   ########.fr       */
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

	for (int n = 0 ; n < 100; n ++) {
		str[n] = malloc(10);
		//free(str[n]);
		//free(str[n]);
		test[n] = malloc(2047);
		lel[n] = malloc(0);
		//free(lel[n]);
		//free(str[n]);
		//free(test[n]);
		test[n] = realloc(str[n], 4096);
		//free(test[n]);
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
