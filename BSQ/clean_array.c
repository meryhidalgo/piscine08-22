/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:39:53 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/31 11:57:56 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief Creates an array called map without the first info line.
 */
char	*clean_map(char *array, int *dim)
{
	char	*map;
	int		i;
	int		j;
	int		k;

	i = length(array, 0) + 1;
	j = 0;
	k = 0;
	map = (char *)malloc(sizeof(char) * ((dim[0] + 1) * dim[1] + 1));
	while (k < dim[1])
	{
		map[j] = array[i];
		if (array[i] == '\n')
			k++;
		i++;
		j++;
	}
	map[j] = 0;
	return (map);
}
