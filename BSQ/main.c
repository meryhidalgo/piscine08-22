/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:42:37 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/31 13:38:03 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief  Main function calling other functions.
 *
 * @param i
 * @param std
 */
void	manager(char *str)
{
	char	*text;
	char	*map;
	char	symbols[4];
	int		dim[2];
	int		*val;

	val = NULL;
	text = array_dict(size_dict(str), str);
	if (!check_array(text, symbols, &dim[1]) || !check_symbols(symbols)
		|| !check_column(text, &dim[0], &dim[1]))
	{
		write(1, "map error\n", 10);
		exit (0);
	}
	map = clean_map(text, dim);
	loop(map, dim, val, symbols);
	free(map);
	free (text);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		ft_stdin();
		manager("stdin.txt");
	}
	while (i < argc)
	{
		manager(argv[i]);
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	system("leaks bsq");
	return (0);
}
