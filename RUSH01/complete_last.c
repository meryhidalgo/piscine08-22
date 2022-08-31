/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:27:15 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/21 13:48:25 by mcarazo-         ###   ########.fr       */
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
