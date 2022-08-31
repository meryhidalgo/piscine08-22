/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubemart <rubemart@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:47:02 by rubemart          #+#    #+#             */
/*   Updated: 2022/08/28 21:26:19 by rubemart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

t_element_dicc	*ft_parser_dict(int *i, int *size);
char			*ft_strcrt(char *dest, char *src, int *i);
void			ft_get_char(int *i, char *ch);
void			ft_add_string(t_element_dicc	*p, int *i, char *ch);

t_element_dicc	*ft_parser_dict(int *i, int *size)
{
	char			ch[500];
	t_element_dicc	*p;

	p = malloc((i[4]) * sizeof(t_element_dicc));
	i[1] = 1;
	i[5] = 0;
	*size = i[4];
	i[4] = 0;
	i[9] = 1;
	while (i[1] > 0)
	{
		i[1] = read(i[0], &i[8], 1);
		ft_get_char(i, ch);
		ft_add_string(p, i, ch);
	}
	return (p);
}

void	ft_get_char(int *i, char *ch)
{
	if (i[1] != 0)
	{
		if (!(i[8] <= 32 || i[8] == 127 || i[8] == ':') && i[3] == 0)
		{
			i[6] = i[5];
			i[3] = 1;
		}
		if (!(i[8] <= 32 || i[8] == 127 || i[8] == ':') && i[3] == 1)
		{
			i[7] = i[5];
			ch[i[7]] = i[8];
			i[5]++;
		}
	}
}

void	ft_add_string(t_element_dicc	*p, int *i, char *ch)
{
	if (i[8] == ':' || i[8] == '\n' || i[1] == 0)
	{
		if (i[8] == ':' && i[9] == 1)
			p[i[4]].key = ft_strcrt(malloc((i[5] + 1) * sizeof(char)), ch, i);
		else if (i[9] == -1)
		{
			p[i[4]].value = ft_strcrt(malloc((i[5] + 1) * sizeof(char)), ch, i);
			i[4]++;
		}
		i[9] = i[9] * (-1);
		i[3] = 0;
		i[5] = 0;
	}
}

char	*ft_strcrt(char *dest, char *src, int *i)
{
	while (i[6] <= i[7])
	{
		dest[i[6]] = src[i[6]];
		i[6]++;
	}
	dest[i[6]] = 0;
	return (dest);
}
