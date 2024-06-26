/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:47:23 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/15 14:05:50 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	char	c[5];
	int		i;
	int		j;

	c [2] = ' ';
	i = 0;
	while (i < 99)
	{
		j = i + 1;
		c[0] = 48 + i / 10;
		c[1] = 48 + i % 10;
		while (j < 100)
		{
			c[3] = 48 + j / 10;
			c[4] = 48 + j % 10;
			write (1, c, 5);
			if (i != 98)
				write (1, ", ", 2);
			j++;
		}
		i++;
	}
}

int main ()
{
	ft_print_comb2();
}
