/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:44:01 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/25 18:12:01 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb != 0)
	{
		result = result * (nb);
		nb--;
	}
	return (result);
}

/*#include <stdio.h>
int	main ()
{
	printf("%d\n", ft_iterative_factorial(5));
}*/
