/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:02:58 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/01 15:02:59 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (range == 0)
		return (-1);
	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	if (size < 0)
		size = size * -1;
	*range = (int *)malloc(sizeof(int) * size);
	if (*range == 0)
		return (-1);
	while (i < size)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (size);
}

/*#include <stdio.h>
int	main()
{
	int	min = 3;
	int	max = 8;
	int	i;
	int	*range;

	i = 0;
	printf("%d\n", ft_ultimate_range(&range, min, max));
	printf("%d\n", ft_ultimate_range(0, min, max));
}*/
