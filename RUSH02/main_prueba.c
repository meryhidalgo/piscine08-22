#include "structure.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int				find_max(int size, t_element_dicc	*p);
int				ft_control_num(char *str);
void			iterate_num(char *num, t_element_dicc *array, int size);
t_element_dicc	*read_file(char *dict_file, int *size);


int	check_dict(t_element_dicc *p, int *size, int digits)
{
	p = read_file("numbers.dict", size);
	if (p == 0)
	{
		p = read_file("numbers.dict", size);
		if (p == 0)
		{
			write(1, "Dict Error\n", 11);
			return (0);
		}
	}
	if (find_max(*size, p) < digits)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}
int main(int argc, char **argv)
{
	t_element_dicc	*p;
	int				size;

	p = 0;
	size = 0;
	if (!check_dict(p, &size, ft_control_num(argv[1])))
	{
		write(1, "error\n", 6);
		return (0);
	}
	iterate_num(argv[1], p, size);
	write(1, "\n", 1);
	argc++;
}
