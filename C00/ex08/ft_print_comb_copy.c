/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:11:18 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/17 10:15:57 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(int n)
{
	int		pos;
	char	nb[10];

	if (nb [n - 1] == 10 - n + pos)
		break;
	while (nb[pos] <= 10 - n + pos)
	{
		write(1, nb, n);
		nb[pos + 1] = nb[pos] + 1;
		pos++;
		ft_print_comb(n);
	}
}

int main()
{
	ft_print_comb(9);
}
