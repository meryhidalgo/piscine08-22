/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:15:50 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/31 11:47:20 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	sol;

	i = 0;
	sol = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		sol = sol * 10 + (str[i] - 48);
		i++;
	}
	return (sol);
}
