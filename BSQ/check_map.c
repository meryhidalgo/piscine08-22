/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:35:51 by enrgarci          #+#    #+#             */
/*   Updated: 2022/08/30 21:15:43 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief Returns [x][y] position from a char pointer containing a map
 *
 *
 * @param map The map you want to get a position from
 * @param x The x cordinate
 * @param y The y cordinate
 * @return char The char at [x][y] position
 */
char	get_pos(char *map, int x, int y, int *size)
{
	return (map[y * (size[0] + 1) + x]);
}
