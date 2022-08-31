#include <stdio.h>

int fibonacci (n)
{
	if (n <= 2)
		return (1);
	return fibonacci(n - 1) + fibonacci (n - 2);
}

int main()
{
	printf("%d\n", fibonacci(9));
}
