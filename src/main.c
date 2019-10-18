/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:08:48 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/18 17:03:59 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"
#include <stdio.h>
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char    *(str[1024]);
	char	*test[100];
	char	*(ptr[2]);
   	
	for (int n = 0 ; n < 100; n ++) {
		str[n] = malloc(8);
		//free(str[n]);
		//free(str[n]);
		test[n] = malloc(16);
		printf("str : %p - test : %p\n", str[n], test[n]);
		free(str[n]);
		//test[n] = realloc(str[n], 16);
		//free(test[n]);
    }
	for (int n = 0 ; n < 100; n ++) {
		//free(str[n]);
		//free(str[n]);
		//test[n] = realloc(str[n], 16);
		//free(str[n]);
		//free(test[n]);
	}
	for (int n = 0 ; n < 5; n ++) {
		ptr[n] = malloc(getpagesize() * 100);
	}
	show_alloc_mem();
	return (0);
}
