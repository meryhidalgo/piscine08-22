#include <unistd.h>
void	ft_putstr_non_printable(char *str)
{
	int	i;
	char	*c;

	c = "0123456789abcdef";
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 32 || str[i] > 126)
		{
			write(1, "\\", 1);
			write(1, &c[(unsigned char)str[i] / 16], 1);
			write(1, &c[(unsigned char)str[i] % 16], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	write (1, "\n", 1);
	ft_putstr_non_printable("Coucou tu vas bie\t\vn ?");
	write (1, "\n", 1);
	ft_putstr_non_printable("");
}
