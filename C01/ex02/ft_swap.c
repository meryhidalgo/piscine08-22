#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	z;
	z = *a;
	*a = *b;
	*b = z;
}

int	main ()
{
	int x = 7;
	int y = 8;
	printf("%d %d", x, y);
	ft_swap(&x, &y);
	printf("%d %d", x, y);
}
