#include<stdio.h>
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main()
{
	int	a = 13;
	int b = 5;
	int cociente;
	int resto;
	ft_div_mod(a, b, &cociente, &resto);
	printf("%d %d", cociente, resto);
}
