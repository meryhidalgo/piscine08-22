#include <stdio.h>

int main (void)
{
	int	a;
	int	b;

	a = 42;

	b = a == 42 ? a < 40 ? 11 : 12 : 13;
	printf("%d\n", b);
}
