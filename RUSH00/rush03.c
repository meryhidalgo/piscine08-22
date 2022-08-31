/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:47:58 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/14 11:45:33 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	col_min(int i, int y)
{
	if (i == 0 || i == (y - 1))
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	col_max(int i, int y)
{
	if (i == 0 || i == (y - 1))
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	col_x(int i, int y)
{
	if (i == 0 || i == (y - 1))
		ft_putchar('B');
	else
		ft_putchar(' ');
}

int	variable_control(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write (1, "Error: negative number or null", 30);
		return (0);
	}
	else if (x > 2147483647 || y > 2147483647)
	{
		write (1, "Error: maximum capacity of int", 30);
		return (0);
	}
	else
		return (1);
}

void	rush(int x, int y)
{
	int		i;
	int		j;

	if (variable_control(x, y))
	{
		i = 0;
		while (i < y)
		{
			while (j < x)
			{
				if (j == 0)
					col_min(i, y);
				else if (j == (x - 1))
					col_max(i, y);
				else
					col_x(i, y);
				j++;
			}
			ft_putchar('\n');
			j = 0;
			i++;
		}
	}
}
