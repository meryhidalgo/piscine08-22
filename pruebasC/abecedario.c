#include <unistd.h>
void	abecedario()
{
	char	c;
	char	d;

	c = 'a';
	while (c <= 'z')
	{
		if (c % 2 == 0)
		{
			d = c - 32;
			write (1, &d, 1);
		}
		else
			write (1, &c, 1);
		c++;
	}
}

int	main()
{
	abecedario();
}
