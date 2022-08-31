/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:33:40 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/21 15:33:55 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	variable_control(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		if (i % 2 == 0)
		{
			if (argv[i] < 49 || argv[i] > 52)
				return (0);
		}
		else
		{
			if (argv[i] != 32)
				return (0);
		}
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

void	ft_str(char *argv, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != 0)
	{
		if (i % 2 == 0)
		{
			str[j] = argv[i];
			j++;
		}
		i++;
	}
}
