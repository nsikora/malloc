//
// Created by nathan on 25/09/2019.
//
#include "includes/malloc.h"
#include <stdio.h>
#include <string.h>
int main()
{
    char *str = ft_malloc(14);
    memcpy(str, "Hello World !", 14);
    printf("%p, %p, {%.*s}\n", str, str+14, 14, str);
    return (0);
}