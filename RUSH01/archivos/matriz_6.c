#include <stdio.h>
void	rush(char *str)
{
	int	i;
	int	j;
	int	k;
	char	matrix[6][6];

	i = 0;
	printf("%s\n", str);
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			if (i == 0 && j != 0 && j != 6)
			{
				k = 0;
				while (k < 7)
				{
					//printf("%c\n", str[k]);
					matrix[i][j] = str[k];
					k = k + 2;
				}
			}
			else if (i == 6 && j != 0 && j != 6)
			{
				k = 8;
				while (k < 15)
				{
					matrix[i][j] = str[k];
					k = k + 2;
				}
			}
			else if (j == 0 && i != 0 && i != 6)
			{
				k = 16;
				while (k < 23)
				{
					matrix[i][j] = str[k];
					k = k + 2;
				}
			}
			else if (j == 6 && i != 0 && i != 6)
			{
				k = 24;
				while (k < 31)
				{
					matrix[i][j] = str[k];
					k = k + 2;
				}
			}
			else
				matrix[i][j] = '0';
			printf("%c", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	if (str[0] == 'A')
		printf("Correcto");
}

int	main(int argc, char *argv[])
{
	rush(argv[1]);
}
