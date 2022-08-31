/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:10:17 by enrgarci          #+#    #+#             */
/*   Updated: 2022/08/31 11:49:44 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief receives array with the squares size and finds the biggest and
 * the closest to the upper corner left
 *
 * @param sqr_vals array with the biggest square in each position
 * @param size map's size [][]
 * @return int position in array with max
 */
int	get_max_pos(int *sqr_vals, int *size)
{
	int	i;
	int	max;
	int	pos;

	max = 0;
	i = 0;
	pos = size[0] * size[1] + size[0];
	while (i < (size[0] * size[1]))
	{
		if (sqr_vals[i] > max)
		{
			pos = i;
			max = sqr_vals[i];
		}
		else if (sqr_vals[i] == max && dist(i, size) < dist(pos, size))
		{
			pos = i;
			max = sqr_vals[i];
		}
		i++;
	}
	return (pos);
}

int	dist(int a, int *size)
{
	int	arr[2];

	arr[0] = a / size[0];
	arr[1] = a % size[0];
	return (arr[0] + arr[1]);
}
