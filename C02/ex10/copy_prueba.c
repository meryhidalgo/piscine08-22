#include <string.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
	char	dest[10];
	char	src[7] = "lalala";
	int		n = 0;

	write(1, dest, n);
	strlcpy(dest, src, n);
	printf("%lu\n", strlcpy(dest, src, n));
	write(1, dest, n);
}
