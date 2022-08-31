#include <unistd.h>
#include <stdlib.h>
char	*ini_array(char *array)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		array[i] = '0';
		i++;
	}
	return (array);
}
int main()
{
	char	*array;
	int		i;

	array = (char*)malloc(16);
	array = ini_array(array);
	i = 0;
	while (i < 13)
	{
		write (1, &array[i], 4);
		write (1, "\n", 1);
		i = i + 4;
	}

}
