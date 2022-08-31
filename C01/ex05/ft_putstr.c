#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main()
{
	char string[] ="lalala";

	ft_putstr(&string[0]);
}
