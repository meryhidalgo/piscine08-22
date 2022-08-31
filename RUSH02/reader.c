/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubemart <rubemart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:24:46 by rubemart          #+#    #+#             */
/*   Updated: 2022/08/28 21:27:01 by rubemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

t_element_dicc	*read_file(char *dict_file, int *size);
t_element_dicc	*ft_parser_dict(int *i, int *size);
void			ft_valid_line(int *i);

t_element_dicc	*read_file(char *dict_file, int *size)
{
	int	i[10];

	i[0] = open(dict_file, O_RDONLY);
	i[1] = 1;
	i[2] = 0;
	i[3] = 0;
	i[4] = 0;
	if (i[0] == -1)
		return (0);
	while (i[1] > 0)
	{
		i[1] = read(i[0], &i[8], 1);
		ft_valid_line(i);
		if (i[8] == '\n' || i[1] <= 0 || i[2] == 1)
		{
			if (i[2] == 1 || i[1] < 0)
				return (0);
			if (i[2] == 0 && i[3] == 5)
				i[4]++;
			i[2] = 0;
			i[3] = 0;
		}
	}
	i[0] = open(dict_file, O_RDONLY);
	return (ft_parser_dict(i, size));
}

void	ft_valid_line(int *i)
{
	if (i[2] == 0 && i[8] != '\n' && i[1] != 0)
	{
		if (i[8] >= '0' && i[8] <= '9' && i[3] < 2)
			i[3] = 1;
		else if (i[8] == ' ' && (i[3] == 1 || i[3] == 2))
			i[3] = 3;
		else if (i[8] == ':' && i[3] <= 3 && i[3] > 0)
			i[3] = 4;
		else if (!(i[8] <= 32 || i[8] == 127) && i[3] >= 4)
			i[3] = 5;
		else if (!(i[8] == ' ' && i[3] >= 4))
			i[2] = 1;
	}
}
