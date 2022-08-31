/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:41:31 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/27 11:15:26 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	num;

	num = 0;
	while (nb > (num * num) && num < 46350)
		num++;
	if (nb == (num * num))
		return (num);
	else
		return (0);
}

/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_sqrt(2147483647));
}*/
