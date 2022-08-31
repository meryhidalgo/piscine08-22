#include <unistd.h>
void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		rem;
	int		quo;
	char	c;

	i = 0;
	while (str[i] != 0)
	{
		if (!(31 < str[i] && str[i] < 127))
		{
			write (1, "\\", 1);
			rem = str[i] % 16;
			quo = str[i] / 16 + 48;
			write (1, &quo, 1);
			if (rem < 10)
  				c = 48 + rem;
			else
  				c = 87 + rem;
			write (1, &c, 1);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}
int main()
{
	char	*ip;
	char	string[]="Coucou\ntu vas bien ?";

	ip = &string[0];
	ft_putstr_non_printable(ip);
}
