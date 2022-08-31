#include<stdio.h>
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	z;
	z = *a;
	*a = *a / *b;
	*b = z % *b;
}

int	main()
{
	int a=13;
	int b=5;

	ft_ultimate_div_mod(&a, &b);
	printf("%d %d", a, b);
}
