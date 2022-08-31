/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:03:58 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/28 23:33:31 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void			iterate_num(char *num, t_element_dicc *array, int size);
int				ft_control_num(char *str, int size, t_element_dicc *p);
t_element_dicc	*read_file(char *dict_file, int *size);

void	ft_free(t_element_dicc *p, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(p[i].key);
		free(p[i].value);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_element_dicc	*p;
	int				size;
	char			*filename;

	if (argc == 2)
		filename = "numbers.dict";
	else if (argc == 3)
		filename = argv[2];
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	p = read_file(filename, &size);
	if (p == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (ft_control_num(argv[1], size, p) == 0)
		return (0);
	iterate_num(argv[1], p, size);
	write(1, "\n", 1);
	ft_free(p, size);
	free(p);
}
