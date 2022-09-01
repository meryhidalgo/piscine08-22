/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:05:23 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/09/01 18:04:45 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	len1;
	int	i;

	i = 0;
	len1 = 0;
	while (dest[len1] != 0)
		len1++;
	while (src[i] != 0)
	{
		dest[i + len1] = src[i];
		i++;
	}
	dest[i + len1] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	total_length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	total = 0;
	while (sep[i] != 0)
	{
		total++;
		i++;
	}
	total = total * (size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			total++;
			j++;
		}
		i++;
	}
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*end;

	i = 1;
	end = (char *)malloc(sizeof(char) * (total_length(size, strs, sep) + 1));
	if (size == 0)
		return (0);
	end = ft_strcpy(end, strs[0]);
	end = ft_strcat(end, sep);
	while (i < size)
	{
		end = ft_strcat(end, strs[i]);
		if (i != size - 1)
			end = ft_strcat(end, sep);
		i++;
	}
	end[total_length(size, strs, sep)] = 0;
	return (end);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*sep = "0000";
	char	*str = ft_strjoin(0, argv, sep);
	//printf("%s\n", argv[0]);
	printf("%s\n", str);
	//write(1, str, total_length(argc, argv, sep) + 1);
	argc++;
}