/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 11:47:58 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/15 20:32:23 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	line_min(int j, int x)
{
	if (j == 0 || j == (x - 1))
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	line_max(int j, int x)
{
	if (j == 0 || j == (x - 1))
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	line_x(int j, int x)
{
	if (j == 0 || j == (x - 1))
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
				if (i == 0)
					line_min(j, x);
				else if (i == (y - 1))
					line_max(j, x);
				else
					line_x(j, x);
				j++;
			}
			ft_putchar('\n');
			j = 0;
			i++;
		}
	}
}
