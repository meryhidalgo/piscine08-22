/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_copy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:56:09 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/24 17:26:33 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
		if (base[i] == 43 || base[i] == 45)
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

int	operate_atoi(char *str, int pos, int neg)
{
	int	sol;

	sol = 0;
	while (str[pos] > 47 && str[pos] < 58)
	{
		sol = sol * 10 + (str[pos] - 48);
		pos++;
	}
	if (neg % 2 == 1)
		sol = sol * -1;
	return (sol);
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	pos;

	i = 0;
	neg = 0;
	pos = 0;
	while (str[i] != 0)
	{
		if (!((str[i] > 8 && str[i] < 14) || (str[i] == 32) || (str[i] == 43)))
		{
			if (str[i] == 45)
				neg++;
			else if (str[i] > 47 && str[i] < 58)
			{
				pos = i;
				break ;
			}
			else
				break ;
		}
		i++;
	}
	return (operate_atoi(str, pos, neg));
}

void	write_num(int quo, char *base, int length)
{
	int	num[32];
	int	i;
	int	x;

	i = 0;
	while (quo != 0)
	{
		if (quo % length < 0)
			num[i] = quo % length * (- 1);
		else
			num[i] = quo % length;
		quo = quo / length;
		i++;
	}
	i--;
	while (i >= 0)
	{
		x = num[i];
		write(1, &base[x], 1);
		i--;
	}
}

void	ft_atoi_base(char *str, char *base)
{
	int	length;
	int	quo;
	int	nbr;

	length = 0;
	nbr = ft_atoi(str);
	if (errors(base))
	{
		if (nbr < 0)
			write (1, "-", 1);
		quo = nbr;
		while (base[length] != 0)
			length++;
		write_num(quo, base, length);
	}
}

int main()
{
	char	str[] = "  ---+--+1234ab567";
	char	str2[] = "	 --+	 -+652839djsk89";
	char	str3[] = "-	-- +214748";
	printf("%d\n", ft_atoi(str));
	ft_atoi_base(str, "0123456789abcdef");
	printf("\n");
	printf("%d\n", ft_atoi(str2));
	ft_atoi_base(str2, "0123456789abcdef");
	printf("\n");
	printf("%d\n", ft_atoi(str3));
	ft_atoi_base(str3, "0123456789abcdef");
}
