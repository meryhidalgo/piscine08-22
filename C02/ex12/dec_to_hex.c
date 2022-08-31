#include <unistd.h>
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
		c[i] = quo + 48;
	while (i >= 0)
	{
		write (1, &c[i], 1);
		i--;
	}
}

int main()
{
	dec_to_hex('\n');
}
