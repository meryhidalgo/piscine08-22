/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_max_sqr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:44:07 by enrgarci          #+#    #+#             */
/*   Updated: 2022/08/31 10:53:22 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/**
 * @brief Calculates maximum square from "pos"
 *
 * @param map the map
 * @param obs obstable
 * @param origin contains [x][y]
 * @param size contains [cols][filas]
 * @return int biggest square taking pos as upper corner left
 */
int	calc_max_sqr(char *map, char obs, int *origin, int *size)
{
	int	max;
	int	ix;
	int	iy;

	max = 1;
	if (get_pos(map, origin[0], origin[1], size) == obs)
		return (0);
	ix = max;
	iy = 0;
	while ((origin[0] + max < size[0]) && (origin[1] + max < size[1]))
	{
		while (ix >= 0)
		{
			if (get_pos(map, origin[0] + ix, origin[1] + iy, size) == obs)
				return (max);
			if (iy < max)
				iy++;
			else
				ix--;
		}
		ix = ++max;
		iy = 0;
	}
	return (max);
}
