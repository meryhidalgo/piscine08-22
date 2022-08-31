/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:20:27 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/21 15:33:18 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(char *str);
int		variable_control(char *argv);
void	ft_str(char *argv, char *str);

int	main(int argc, char *argv[])
{
	char	str[16];

	if (argc != 2)
		return (0);
	if (variable_control(argv[1]))
	{
		ft_str(argv[1], str);
		rush(str);
	}
	else
		write (1, "Error\n", 6);
}
