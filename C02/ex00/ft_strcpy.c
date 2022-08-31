#include <stdio.h>
#include <unistd.h>
char	*ft_strcpy(char *dest, char *src)
{
	int 	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


int	main()
{
	char dest[10];
	char src[7] = "lalala";
	//write(1, src, 7);
	ft_strcpy(dest, src);
	printf("%s\n", dest);
}
