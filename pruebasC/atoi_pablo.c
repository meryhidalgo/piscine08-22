#include <stdio.h>
int	ft_atoi_pablo(char *str)
{
	int	out;
	int	bol;

	bol = 1;
	out = 0;
	while (*str != 0)
	{
		if (!((*str >= '0' && *str <= '9') || *str == 32 || (*str > 8 && *str < 14) || *str == '-' || *str == '+'))
			break ;
		if (*str >= '0' && *str <= '9')
			out = out * 10 + (*str - '0');
		if (*str == '-')
			bol = -bol;
		str++;
	}
	return(out * bol);
}

int	main (void)
{
	char	str[] = " ---	-+--+1234ab567";
	printf("%d", ft_atoi_pablo(str));
}
