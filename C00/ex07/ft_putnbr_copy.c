#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	j;

	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else if (nb < 0)
	{
		write (1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
	   if (nb/10 != 0)
			ft_putnbr(nb/10);
		j = nb % 10 + 48;
		write (1, &j, 1);
	}
}

int	main()
{
	ft_putnbr(2147483648);
}
