#include <unistd.h>
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((src[i] != 0) && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

int	main ()
{
	char dest[10];
	char src[] = "lalala";
	unsigned int	n = 3;
	write(1, ft_strncpy(dest, src, n), n);
}
