//
// Created by nathan on 25/09/2019.
//
#include "includes/malloc.h"
#include <sys/mman.h>
#include <stdio.h>
#include <string.h>
int main()
{
    for (int n = 0 ; n < 1024 ; n ++) {
        char *str = ft_malloc(getpagesize());
        memcpy(str, "Hello World !", 14);
        printf("%p, %p, {%.*s}, %d\n", str, str + getpagesize(), 14, str, n);
    }
   return (0);
}