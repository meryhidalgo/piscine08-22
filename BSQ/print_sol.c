/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:18:02 by enrgarci          #+#    #+#             */
/*   Updated: 2022/08/31 12:00:41 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	row(int a, int *size)
{
	return (a / size[0]);
}

int	col(int a, int *size)
{
	return (a % size[0]);
}

/**
 * @brief prints map with solution
 *
 * @param map the map
 * @param sol  position to print in []
 * @param sq size of the square to print (upper left)
 * @param size array with the map dimensions
 */
void	print_sol(char *map, int *sol, char sqr_symb, int *size)
{
	int	i;
	int	line;
	int	r_i;

	line = 0;
	i = 0;
	r_i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			ft_putchar(map[i]);
			r_i--;
		}
		else if (row(r_i, size) >= row(sol[0], size)
			&& row(r_i, size) < (row(sol[0], size) + sol[1])
			&& col(r_i, size) >= col(sol[0], size)
			&& col(r_i, size) < col(sol[0], size) + sol[1])
			ft_putchar(sqr_symb);
		else
			ft_putchar(map[i]);
		i++;
		r_i++;
	}
}
