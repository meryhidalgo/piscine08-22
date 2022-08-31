/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_with_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:21:39 by igvisera          #+#    #+#             */
/*   Updated: 2022/08/28 18:21:42 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	compare(char *num, t_element_dicc *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(array[i].key, num) == 0)
		{
			j = 0;
			while (array[i].value[j] != 0)
			{
				write(1, &array[i].value[j], 1);
				j++;
			}
			write(1, " ", 1);
		}
		i++;
	}
	free(num);
}
