/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:01:26 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/01 15:01:26 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	i = 0;
	if (min >= max)
	{
		range = NULL;
		return (range);
	}
	size = max - min;
	if (size < 0)
		size = size * -1;
	range = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}

/*#include <stdio.h>
int	main()
{
	int	min = -3;
	int	max = 8;
	int	size;
	int	i;
	int	*range;

	i = 0;
	size = max - min;
	if (size < 0)
		size = size * -1;
	range = ft_range(min, max);
	while (i < size)
	{
		printf("%d", range[i]);
		i++;
	}
}*/
