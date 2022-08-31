/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:05:14 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/31 12:02:05 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	length(char *array, int i)
{
	while (array[i] != '\n')
	{
		if (!(31 < array[i] && array[i] < 127))
			return (0);
		i++;
	}
	return (i);
}

/**
 * @brief creates an int with row size
 */
int	rows(char *array)
{
	int		i;
	char	*rows;
	int		row;

	i = 0;
	rows = (char *)malloc(sizeof(char) * (length(array, 0) - 3 + 1));
	while (i < length(array, 0) - 3)
	{
		rows[i] = array[i];
		i++;
	}
	rows[i] = 0;
	row = ft_atoi(rows);
	free(rows);
	return (row);
}

/**
 * @brief checks all symbols are printable, there isn't any one missing
 * and creates symbols.
 * Also checks there arent any external symbols and there is at least one empty
 * @param symbols array with empty, obs, fill
 */
int	check_array(char *array, char *symbols, int *row)
{
	int	i;
	int	j;
	int	empty;

	i = length(array, 0);
	if (i < 4)
		return (0);
	j = i + 1;
	create_symbols(symbols, array, i - 1);
	*row = rows(array);
	i = 0;
	empty = 0;
	while (i < *row)
	{
		if (array[j] != symbols[0] && array[j] != symbols[1]
			&& array[j] != '\n')
			return (0);
		if (array[j] == '\n')
			i++;
		else if (array[j] == symbols[0])
			empty = 1;
		j++;
	}
	return (empty);
}

/**
 * @brief checks all columns have the same length
 */
int	check_column(char *array, int *col, int *row)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = length(array, 0);
	*col = length(array, i + 1);
	*col = *col - i;
	i++;
	while (k < *row - 1)
	{
		j = length(array, i);
		if ((*col - 1) != (j - i))
			return (0);
		if (array[j] == '\n')
			k++;
		i = i + *col;
	}
	*col = *col - 1;
	return (1);
}
