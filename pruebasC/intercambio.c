#include<stdio.h>
void	intercambia (int x, int y)
{
	int	z;

	z = x;
	x = y;
	y = z;
}
int	main(void)
{
	int a=7;
	int b=8;
	printf("%d %d", a, b);
	intercambia(a, b);
	printf("%d %d", a, b);
//NO funciona porque x e y hacen una copia de los valores de a y b.
}
