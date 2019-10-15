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

    for (int n = 0 ; n < 1024 ; n ++) {
        str[n] = ft_malloc(getpagesize());
        memcpy(str[n], "Hello World !", 14);
		printf("%p\n", str[n]);
      	printf("%p, %p, %s, %d\n", str[n], str[n] + getpagesize(), str[n], n);
    }

    for (int n = 0 ; n < 1024 ; n ++) {
        ft_free(str[n]);
    }
   return (0);
}
