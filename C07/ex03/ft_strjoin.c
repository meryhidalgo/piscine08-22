/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:05:23 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/01 18:20:40 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	complete_array(int size, char *end, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			end[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] != 0 && i != (size - 1))
		{
			end[k] = sep[j];
			j++;
			k++;
		}
		i++;
	}
	end[k] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		lng;
	char	*end;

	i = 0;
	if (size == 0)
		return (0);
	lng = ft_strlen(sep) * (size - 1);
	while (i < size)
	{
		lng = lng + ft_strlen(strs[i]);
		i++;
	}
	end = (char *)malloc(sizeof(char) * lng + 1);
	if (end == NULL)
		return (0);
	complete_array(size, end, strs, sep);
	return (end);
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*sep = "0000";
	char	*str = ft_strjoin(argc, argv, sep);
	//printf("%lu\n", sizeof(sep));
	//printf("%s\n", argv[0]);
	printf("%s\n", str);
	argc++;
}*/