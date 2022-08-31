/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:14:58 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/28 18:15:49 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*zeros(int x);
char	*ft_tens(char u);
char	*ft_onetens(char u, char v);
char	*ft_units(char z);
int		ft_strcmp(char *s1, char *s2);
void	compare(char *num, t_element_dicc *array, int size);

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

void	check_unit(int pos, char digit, t_element_dicc *array, int size)
{
	if (pos % 3 == 0 && digit != '0')
	{
		compare(ft_units(digit), array, size);
		compare(zeros(3), array, size);
	}
}

void	check_hundred(int pos, char digit, t_element_dicc *array, int size)
{
	if (pos % 3 == 1 && digit != '0')
		compare(ft_units(digit), array, size);
	if (pos % 3 == 1 && pos / 3 > 0)
		compare(zeros(pos), array, size);
}

void	iterate_num(char *num, t_element_dicc *array, int size)
{
	int	k;
	int	pos;

	k = 0;
	if (num[k] == '0' && num[k + 1] == 0)
	{
		compare(ft_units(num[k]), array, size);
		return ;
	}
	while (num[k] != 0)
	{
		pos = ft_strlen(num) - k;
		check_unit(pos, num[k], array, size);
		if (pos % 3 == 2 && num[k] == '1')
		{
			compare(ft_onetens(num[k], num[k + 1]), array, size);
			if ((pos - 1) / 3 > 0)
				compare(zeros(pos - 1), array, size);
			k++;
		}
		else if (pos % 3 == 2 && num[k] != '0')
			compare(ft_tens(num[k]), array, size);
		check_hundred(pos, num[k], array, size);
		k++;
	}
}
