/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:15:50 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/25 15:39:31 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	sol;

	i = 0;
	neg = 1;
	sol = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = neg * -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		sol = sol * 10 + (str[i] - 48);
		i++;
	}
	return (sol * neg);
}

/*#include <stdio.h>
int main()
{
	char	str[] = " ---+--+1234ab567";
	char	str2[] = "	 --+	 -+652839djsk89";
	printf("%d\n", ft_atoi(str));
	printf("%d\n", ft_atoi(str2));
}*/
