/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:41:47 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/21 15:13:53 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_col_ini1(char *array, char *str);

void	ft_col_ini2(char *array, char *str);

void	ft_row_ini1(char *array, char *str);

void	ft_row_ini2(char *array, char *str);

void	ft_complete_2_3(char *array, char *str);

void	ini_array(char *array)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		array[i] = '0';
		i++;
	}
}

void	rush(char *str)
{
	int		i;
	char	array[16];

	ini_array(array);
	ft_col_ini1(array, str);
	ft_col_ini2(array, str);
	ft_row_ini1(array, str);
	ft_row_ini2(array, str);
	ft_complete_2_3(array, str);
	i = 0;
	while (i < 13)
	{
		write (1, &array[i], 4);
		write (1, "\n", 1);
		i = i + 4;
	}
}
