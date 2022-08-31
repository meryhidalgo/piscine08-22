#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int i;

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

void	dec_to_hex (long b)
{
	long	rem;
	long	quo;
	char	c[16];
	int		i;

	i = 0;
	quo = b;
	while (quo != 0)
	{
		rem = quo % 16;
		if (rem > 9)
			c[i] = 87 + rem;
		else
			c[i] = 48 + rem;
		quo = quo / 16;
		i++;
	}
	if (i == 1)
	{
		c[i] = '0';
		i++;
	}
	c[i] = quo;
	while (i >= 0)
	{
		write (1, &c[i], 1);
		i--;
	}
}

//426f 6e6a 0a75 7220 6c65 7320 616d 696e
void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	int		z;
	long	n;
	char	*str;

	i = 0;
	str = (char *)addr;
	n = (long) &addr[0];
	write (1, "000000010", 9);
	dec_to_hex (n);
	write (1, ": ", 2);
	while (str[i] != '\0')
	{
		if (i % 2 == 0 && i != 0)
			write (1, " ", 1);
		dec_to_hex ((long) str[i]);
		i++;
	}
	while (i < 16)
	{
		write (1, " ", 1);
		i++;
	}
	write (1, " ", 1);
	ft_putstr(str);
	write (1, "\n", 1);
	return (addr);
}

int main()
{
	char	frase[] = "Bonj\nur les amin";
	char	frase2[] = "u\ntout\nce qu on";
	ft_print_memory(frase, sizeof(frase));
	ft_print_memory(frase2, sizeof(frase2));
}
