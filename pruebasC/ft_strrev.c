#include <stdio.h>
char	*ft_strrev(char *str)
{
	int		i;
	int		length;
	char	aux;

	i = 0;
	length = 0;
	while (str[length] != 0)
		length++;
	while (i < length / 2)
	{
		aux = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = aux;
		i++;
	}
	return (str);
}

int main()
{
	char	string[] = "Hola";
	printf("%s\n", ft_strrev(string));
}
