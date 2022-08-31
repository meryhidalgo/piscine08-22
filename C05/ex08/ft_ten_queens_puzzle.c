/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diez_damas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:38:25 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/25 16:38:25 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_array(int	*comb)
{
	int		j;
	char	c;

	j = 0;
	while (j < 10)
	{
		c = comb[j] + 48;
		write (1, &c, 1);
		j++;
	}
	write (1, "\n", 1);
}

int	ft_correct(int *comb, int i)
{
	int	k;

	k = i - 1;
	while (k >= 0)
	{
		if ((comb[i] == comb[k]) || (i + comb[i] == k + comb[k])
			|| (i - comb[i] == k - comb[k]))
			return (0);
		k--;
	}
	return (1);
}

void	ft_recursive(int *comb, int i, int *ptr)
{
	if (comb[i] > 9)
		return ;
	while (comb[i] < 9)
	{
		comb[i] = comb[i] + 1;
		if (ft_correct(comb, i))
		{
			if (i < 9)
				ft_recursive(comb, i + 1, ptr);
			else
			{
				print_array(comb);
				(*ptr)++;
			}
		}
	}
	comb[i] = -1;
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	comb[10];
	int	*ptr;
	int	lap;

	i = 0;
	lap = 0;
	ptr = &lap;
	while (i < 10)
	{
		comb[i] = -1;
		i++;
	}
	i = 0;
	ft_recursive(comb, i, ptr);
	return (lap);
}

/*#include <stdio.h>
int	main()
{
	printf("%d\n", ft_ten_queens_puzzle());
}*/
