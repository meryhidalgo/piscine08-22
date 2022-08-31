/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:28:24 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/15 11:49:35 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	numb_digit(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i ++;
		n = n / 10;
	}
	return (i);
}

int	power(int base, int exp)
{
	int	i;
	int	result;

	i = exp;
	result = base;
	while (i > 1)
	{
		result *= base;
		i --;
	}
	return (result);
}

void	print_number(int nb)
{
	int	i;
	int	j;

	while (nb / 10 != 0)
	{
		i = nb / power(10, numb_digit(nb) - 1) + 48;
		nb = nb % power(10, numb_digit(nb) - 1);
		j = 48 + nb % 10;
		write (1, &i, 1);
	}
	write (1, &j, 1);
}

void	ft_putnbr(int nb)
{
	int	j;

	if (nb == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write (1, "-", 1);
			nb = nb * -1;
		}
		if (nb < 10)
		{
			j = 48 + nb % 10;
			write (1, &j, 1);
		}
		else
			print_number(nb);
	}
}

int main ()
{
	ft_putnbr(30);
}
