/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:27:55 by enrgarci          #+#    #+#             */
/*   Updated: 2022/08/31 13:24:50 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	loop(char *map, int *size, int *sqr_val, char *symbols)
{
	int	i;
	int	j;
	int	pos[2];
	int	pos_sqr[2];

	sqr_val = malloc(sizeof(int) * size[0] * size[1]);
	i = 0;
	while (i < size[1])
	{
		j = 0;
		while (j < size[0])
		{
			pos[0] = j;
			pos[1] = i;
			sqr_val[i * size[0] + j] = calc_max_sqr(map, symbols[1], pos, size);
			j++;
		}
		i++;
	}
	pos_sqr[0] = get_max_pos(sqr_val, size);
	pos[0] = pos_sqr[0] % size[0];
	pos[1] = pos_sqr[0] / size[0];
	pos_sqr[1] = calc_max_sqr(map, symbols[1], pos, size);
	print_sol(map, pos_sqr, symbols[2], size);
	free(sqr_val);
}
