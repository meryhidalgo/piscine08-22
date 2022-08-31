/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:58:44 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/24 19:27:02 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		length;
	char	*ocurrence;

	i = 0;
	j = 0;
	length = 0;
	if (to_find[0] == 0)
		return (str);
	while (str[i] != 0 && to_find[j] != 0)
	{
		if (str[i + j] == to_find[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	ocurrence = str + i;
	if (j > 0)
		return (ocurrence);
	else
		return (0);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	string[] = "Buenos ddias por la mmañana";
	char	to_find[] = "dia";
	printf("%s\n", ft_strstr(string, to_find));
	printf("%s\n", strstr(string, to_find));
}*/
