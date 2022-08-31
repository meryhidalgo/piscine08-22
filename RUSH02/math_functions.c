/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:05:19 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/28 16:05:20 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*zeros(int x)
{
	char	*str;
	int		i;

	i = 1;
	str = (char *)malloc(sizeof(char) * (x + 1));
	str[0] = '1';
	while (i < x)
	{
		str[i] = '0';
		i++;
	}
	str[x] = 0;
	return (str);
}

char	*ft_tens(char u)
{
	char	*dec;

	dec = (char *)malloc(sizeof(char) * (2 + 1));
	dec[0] = u;
	dec[1] = '0';
	dec[2] = 0;
	return (dec);
}

char	*ft_onetens(char u, char v)
{
	char	*dec1;

	dec1 = (char *)malloc(sizeof(char) * (2 + 1));
	dec1[0] = u;
	dec1[1] = v;
	dec1[2] = 0;
	return (dec1);
}

char	*ft_units(char z)
{
	char	*ud;

	ud = (char *)malloc(sizeof(char) * (1 + 1));
	ud[0] = z;
	ud[1] = 0;
	return (ud);
}
