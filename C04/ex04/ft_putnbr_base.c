/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:32:16 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/25 21:08:32 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	errors(char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i] != 0)
	{
		if (base[i] == 43 || base[i] == 45 || base[i] == 32)
			return (0);
		j = i - 1;
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

void	write_num(int i, int *num, char *base)
{
	int	x;

	i--;
	while (i >= 0)
	{
		x = num[i];
		write(1, &base[x], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	length;
	int	num[33];
	int	i;
	int	quo;

	i = 0;
	if (errors(base))
	{
		if (nbr == 0)
			write (1, &base[0], 1);
		else if (nbr < 0)
			write (1, "-", 1);
		quo = nbr;
		length = ft_strlen(base);
		while (quo != 0)
		{
			if (quo % length < 0)
				num[i] = quo % length * (-1);
			else
				num[i] = quo % length;
			quo = quo / length;
			i++;
		}
		write_num(i, num, base);
	}
}

/*int	main(void)
{
	ft_putnbr_base(2147483647, "0123456789abcdef");
}*/
