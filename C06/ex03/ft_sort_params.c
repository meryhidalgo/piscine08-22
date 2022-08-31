/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:06:42 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/29 10:24:33 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	print_param(char *str)
{
	int	j;

	j = 0;
	while (str[j] != 0)
	{
		write (1, &str[j], 1);
		j++;
	}
	write (1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int		pos;
	int		i;
	int		min;
	char	*aux;

	pos = 1;
	while (pos < argc - 1)
	{
		i = pos + 1;
		min = pos;
		while (i < argc)
		{
			if (ft_strcmp(argv[i], argv[min]) < 0)
				min = i;
			i++;
		}
		aux = argv[pos];
		argv[pos] = argv[min];
		argv[min] = aux;
		print_param(argv[pos]);
		pos++;
	}
	if (argc > 1)
		print_param(argv[pos]);
}
