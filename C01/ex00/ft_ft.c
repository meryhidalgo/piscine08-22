#include <stdio.h>

void	ft_ft(int *nbr)
{	
	*nbr = 42;
}

int	main()
{

	int entero;
	ft_ft(&entero);
	printf("%d\n", entero);
}
