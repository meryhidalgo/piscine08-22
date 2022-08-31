#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!(31 < str[i] && str[i] < 127))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

void	dec_to_hex_addr(long b)
{
	long	rem;
	long	quo;
	char	addr[16];
	int		i;

	i = 15;
	quo = b;
	while (quo != 0)
	{
		rem = quo % 16;
		if (rem > 9)
			addr[i] = 87 + rem;
		else
			addr[i] = 48 + rem;
		quo = quo / 16;
		i--;
	}
	while (i >= 0)
	{
		addr[i] = 48;
		i--;
	}
	write(1, addr, 16);
}

void	dec_to_hex_str(char *str)
{
	int		i;
	int		rem;
	int		quo;

	i = 0;
	while (str[i] != 0)
	{
		if (i % 2 == 0 && i != 0)
			write (1, " ", 1);
		rem = str[i] % 16;
		quo = str[i] / 16 + 48;
		write (1, &quo, 1);
		if (rem < 10)
			rem = 48 + rem;
		else
			rem = 87 + rem;
		write (1, &rem, 1);
		i++;
	}
	while (i < 16)
	{
		write (1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	long	n;
	char	*str;

	if (size == 0)
		return (addr);
	i = 0;
	str = (char *)addr;
	n = (long) &addr[0];
	dec_to_hex_addr (n);
	write (1, ": ", 2);
	dec_to_hex_str (str);
	write (1, " ", 1);
	ft_putstr(str);
	write (1, "\n", 1);
	return (addr);
}

int	main(void)
{
	char	frase[] = "Bonj\nur les am";
	char	frase2[] = "u\ntout\nce qu on ";
	ft_print_memory(frase, sizeof(frase));
	ft_print_memory(frase2, sizeof(frase2));
}
