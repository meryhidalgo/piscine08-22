/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:51:26 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/25 15:51:26 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	check_base(char *base, char x)
{
	int	j;

	j = 0;
	while (base[j] != 0)
	{
		if (x == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

int	operate_atoi(char *str, int i, int neg, char *base)
{
	int	sol;
	int	length_base;
	int	k;
	int	aux;

	sol = 0;
	k = 0;
	length_base = 0;
	i--;
	while (base[length_base] != 0)
		length_base++;
	while (i >= 0)
	{
		if (check_base(base, str[i]) >= 0)
		{
			aux = ft_recursive_power(length_base, k) * check_base(base, str[i]);
			sol = sol + aux;
			k++;
		}
		i--;
	}
	return (sol * neg);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	length_num;

	i = 0;
	neg = 1;
	length_num = 0;
	if (!errors(base))
		return (0);
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			neg = neg * -1;
		i++;
	}
	while (check_base(base, str[i]) >= 0)
		i++;
	return (operate_atoi(str, i, neg, base));
}

#include <stdio.h>
int main()
{
	char	str[] = "";
	printf("%d\n", ft_atoi_base(str, "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("1010101111001", "01"));
}
