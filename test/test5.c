#include <stdlib.h>

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main()
{
	char	*addr;

	addr = malloc(16);
	print("0\n");
	free(NULL);
	print("1\n");
	free((void *)addr + 5);
	print("2\n");
	if (realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
}
