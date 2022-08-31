/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_1_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:40:43 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/21 15:13:12 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_col_ini1(char *array, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0 && i < 4)
	{
		if (str[i] == '4')
		{
			array[i] = '1';
			array[i + 4] = '2';
			array[i + 8] = '3';
			array[i + 12] = '4';
		}
		else if (str[i] == '1')
			array[i] = '4';
		i++;
	}
}

void	ft_col_ini2(char *array, char *str)
{
	int	i;

	i = 4;
	while (str[i] != 0 && i < 8)
	{
		if (str[i] == '4')
		{
			array[4 * 3 + (i - 4)] = '1';
			array[4 * 2 + (i - 4)] = '2';
			array[4 * 1 + (i - 4)] = '3';
			array[4 * 0 + (i - 4)] = '4';
		}
		else if (str[i] == '1')
			array[4 * 3 + (i - 4)] = '4';
		i++;
	}
}

void	ft_row_ini1(char *array, char *str)
{
	int	i;

	i = 8;
	while (str[i] != 0 && i < 12)
	{
		if (str[i] == '4')
		{
			array[(i - 8) * 4] = '1';
			array[(i - 8) * 4 + 1] = '2';
			array[(i - 8) * 4 + 2] = '3';
			array[(i - 8) * 4 + 3] = '4';
		}
		else if (str[i] == '1')
			array[(i - 8) * 4] = '4';
		i++;
	}
}

void	ft_row_ini2(char *array, char *str)
{
	int	i;

	i = 12;
	while (str[i] != 0 && i < 16)
	{
		if (str[i] == '4')
		{
			array[(i - 11) * 4 - 1] = '1';
			array[(i - 11) * 4 - 2] = '2';
			array[(i - 11) * 4 - 3] = '3';
			array[(i - 11) * 4 - 4] = '4';
		}
		else if (str[i] == '1')
			array[(i - 11) * 4 - 1] = '4';
		i++;
	}
}
