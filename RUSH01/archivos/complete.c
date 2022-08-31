/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:27:15 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/21 13:39:14 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	complete_one_row(char *array, int pos)
{
	int	sum;
	int	empty;
	int	i;

	i = pos;
	while (i < pos + 4)
	{
		if (array[i] == '0')
			empty = i;
		sum = sum + array[i] - 48;
		i++;
	}
	if (sum < 10)
		array[empty] = 10 - sum + 48;
}

void	complete_one_col(char *array, int pos)
{
	int	sum;
	int	empty;
	int	i;

	i = pos;
	while (i <= 4 * 3 + pos)
	{
		if (array[i] == '0')
			empty = i;
		sum = sum + array[i] - 48;
		i = i + 4;
	}
	if (sum < 10)
		array[empty] = 10 - sum + 48;
}

int	main(void)
{
	char array[16] = {'0', '2', '3', '4', '2', '0', '4', '1', '3', '4', '0', '2', '4', '1', '2', '0'};
	int	i;

	i = 0;
	complete_one_row(array, 12);
	while (i < 13)
	{
		write (1, &array[i], 4);
		write (1, "\n", 1);
		i = i + 4;
	}
}

void	complete_row(char *array)
{
	int	i;
	int	j;
	int	sum;
	int	empty;

	i = 4;
	j = 0;
	while (i <= 16)
	{
		sum = 0;
		while (j < i)
		{
			if (array[j] == '0')
				empty = j;
			sum = sum + array[j] - 48;
			j++;
		}
		if (sum < 10)
			array[empty] = 10 - sum + 48;
		i = i + 4;
	}
}

void	complete_col(char *array)
{
	int	i;
	int	j;
	int	sum;
	int	empty;

	i = 0;
	j = 0;
	while (i < 4)
	{
		sum = 0;
		j = i;
		while (j <= 12 + i)
		{
			if (array[j] == '0')
				empty = j;
			sum = sum + array[j] - 48;
			j = j + 4;
		}
		if (sum < 10)
			array[empty] = 10 - sum + 48;
		i++;
	}
}
