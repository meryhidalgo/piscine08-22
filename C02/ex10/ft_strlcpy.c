#include <stdio.h>
#include <unistd.h>
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	length = 0;
	while (src[length] != 0)
		length++;
	while (i < length + 1 && i < size)
	{
		if (i == size - 1)
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
	return (length);
}

#include <stdlib.h>
int	main()
{
	char dest[100];
	char src[7] = "lalala";
	int	n = 3;

	printf("%d\n", ft_strlcpy(dest, src, n));
	int i = 0;
	while (i < n)
	{
		write(1, &dest[i], 1);
		i++;
	}
}
