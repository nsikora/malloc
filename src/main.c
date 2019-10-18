/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:08:48 by nsikora           #+#    #+#             */
/*   Updated: 2019/10/18 11:47:28 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/malloc.h"
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char    *(str[1024]);
	char	*test[100];
	char	*(ptr[2]);
   	
	for (int n = 0 ; n < 100; n ++) {
		str[n] = malloc(getpagesize());
		test[n] = realloc(str[n], 50);
    }
	for (int n = 0 ; n < 100; n ++) {
		//test[n] = reallocf(str[n], 50);
		//free(str[n]);
		free(test[n]);
	}
	for (int n = 0 ; n < 5; n ++) {
		ptr[n] = malloc(getpagesize() * 100);
 		//free(ptr[n]);
	}
	show_alloc_mem();
	return (0);
}
