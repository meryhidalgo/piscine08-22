#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	aux;

	i = 0;
	while (i < size / 2)
	{
		aux = tab[i];
		tab[i] = tab [size - i - 1];
		tab [size - i - 1] = aux;
		i++;
	}
}

int	main()
{
	int	array[7] = {1, 2, 3, 4, 5, 6, 7};

	for (int i = 0; i < 7; i++)
	{
		printf("%d",  array[i]);
	}
	printf("\n");
	ft_rev_int_tab(&array[0], 7);
	for (int i = 0; i < 7; i++)
	{
		printf("%d",  array[i]);
	}
}
