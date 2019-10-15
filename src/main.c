//
// Created by nathan on 25/09/2019.
//
#include "includes/malloc.h"
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char    *(str[1024]);

    for (int n = 0 ; n < 1024; n ++) {
        str[n] = ft_malloc(getpagesize());
      	//ft_free(str[n]);
    }
	show_alloc_mem();
   return (0);
}
