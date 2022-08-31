#include<stdio.h>

int	ft_strlen(char *str)
{
	int length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

int main()
{
	char string[] ="lalala";

	printf("%d\n", ft_strlen(&string[0]));
}
