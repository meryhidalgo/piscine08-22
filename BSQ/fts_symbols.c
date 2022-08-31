/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:55:03 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/31 11:58:40 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Creates an array with empty, obstacle and full symbols
 * @param symbols
 */
void	create_symbols(char *symbols, char *array, int pos)
{
	int	i;

	i = 2;
	while (i >= 0)
	{
		symbols[i] = array[pos];
		pos--;
		i--;
	}
	symbols[3] = 0;
}

/**
 * @brief Checks there aren't two same symbols
 */
int	check_symbols(char *symbols)
{
	int	i;
	int	j;

	i = 0;
	while (symbols[i] != 0)
	{
		j = i + 1;
		while (symbols[j] != 0)
		{
			if (symbols[i] == symbols[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
