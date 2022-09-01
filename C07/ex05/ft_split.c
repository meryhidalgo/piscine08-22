#include <stdio.h>
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	total_splits(char *str, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (charset[j] != 0)
		{
			if (str[i] == charset[j])
				k++;
			j++;
		}
		i++;
	}
	return (k + 1);
}

char	**ft_split(char *str, char *charset)
{
	char	**split = 0;
	int		q;

	q = 0;
	while (q < total_splits(str, charset))
	{
		split[q] = ft_strcpy(split[i], ¿??)
		q++;
	}
	printf("%d\n", total_splits(str, charset));
	return(split);
}

int	main(int argc, char **argv)
{
	ft_split(argv[1], argv[2]);
	argc++;
}