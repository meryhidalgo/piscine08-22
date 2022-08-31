#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	pos;
	int	i;
	int	min;
	int	aux;

	pos = 0;
	while (pos < size - 1)
	{
		i = pos + 1;
		min = pos;
		while (i < size)
		{
			if (tab[i] <=  tab[min])
				min = i;
			i++;
		}
		aux = tab [pos];
		tab[pos] = tab[min];
		tab[min] = aux;
		pos++;
	}

}	
int	main()
{
	int	array[10] = {9, 4, 1, 8, 23, 7, 555, -13, -4, 0};

	for (int i = 0; i < 10; i++)
	{
		printf("%d",  array[i]);
	}
	printf("\n");
	ft_sort_int_tab(&array[0], 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d",  array[i]);
	}
}
