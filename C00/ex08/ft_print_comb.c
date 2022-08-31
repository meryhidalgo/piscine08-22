/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:11:18 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/15 12:03:34 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(int n)
{
	int		pos;
	char	nb[10];

	nb[0] = 48;
	pos = 0;
	while (pos++ < n - 1)
		nb[pos] = nb[pos - 1] + 1;
	while (nb[0] != 10 - n + 48)
	{
		if (nb[n - 1] > 57)
		{
			pos = n - 2;
			while (nb[pos] == 10 - n + pos + 48)
				pos--;
			nb[pos]++;
			while (pos++ < (n - 1))
				nb[pos] = nb[pos - 1] + 1;
		}
		write(1, nb, n);
		if (nb[0] != 10 - n + 48)
			write (1, ", ", 2);
		nb[n - 1]++;
	}
	if (n == 1)
		write (1, "9", 1);
}

int main()
{
	ft_print_comb(9);
}
