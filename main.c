/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikora <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:36:41 by nsikora           #+#    #+#             */
/*   Updated: 2019/09/19 11:34:28 by nsikora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "malloc.h"

void print_rlimit(struct rlimit *r, const char *name) {
	size_t cur;                /* Soft limit */
	size_t max;                /* Hard limit */
	cur = r->rlim_cur;
	max = r->rlim_max;
	printf("RLIMIT_%s :\nrlim_cur => %zu,\n :rlim_max => %zu\n", name, cur, max);
}

char *first_adress;

int 		main()
{
	struct 	rlimit rlim;
	size_t	lel;

	int resources[] = {RLIMIT_CORE, RLIMIT_CPU, RLIMIT_DATA, RLIMIT_FSIZE, RLIMIT_MEMLOCK,
		RLIMIT_NOFILE, RLIMIT_NPROC, RLIMIT_RSS, RLIMIT_STACK};
	const char *names[] = {"CORE", "CPU", "DATA", "FSIZE", "MEMLOCK", "NOFILE", "NPROC", "RSS", "STACK"};
	int n = sizeof(resources)/sizeof(resources[0]);
	int i;
	for (i = 0; i < n; i++) {
		getrlimit(resources[i], &rlim);
		print_rlimit(&rlim, names[i]);
	}
	lel = getpagesize();
	printf("%zu\n", lel);
	return (0);
}

