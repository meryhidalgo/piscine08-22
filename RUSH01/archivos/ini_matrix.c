#include <stdio.h>
#include <stdlib.h>
int	**initialize_matrix(int **matrix, int r, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			matrix[i][j] = 0;
			printf("%d", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (matrix);
}
//void	ft_skyscraper(char *str)


int	main ()
{
	int	r = 4;
	int	c = 4;
	int	*ptr;
	int	**matrix;

	ptr = malloc(r*c*sizeof(int*));

	matrix = (int **)malloc(sizeof(int *) * 4);
	int i = 0;
	while (i < 4)
	{
		matrix[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}

	initialize_matrix(matrix, r, c);
	/*for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%d", matrix[i][j]);
		printf("\n");
	}*/
}
