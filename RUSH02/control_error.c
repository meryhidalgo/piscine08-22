/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:24:01 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/28 23:33:12 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	find_max(int size, t_element_dicc	*p)
{
	int	j;
	int	max;

	j = 0;
	max = 0;
	while (j < size)
	{
		if (ft_strlen(p[j].key) > max)
			max = ft_strlen(p[j].key);
		j++;
	}
	return (max);
}

int	dict_error(int z, int size, t_element_dicc *p)
{
	if (z > (find_max(size, p) + 2))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

int	ft_control_num(char *str, int size, t_element_dicc *p)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (str[0] == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (str[i] == '0')
		i++;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
		z++;
	}
	return (dict_error(z, size, p));
}
