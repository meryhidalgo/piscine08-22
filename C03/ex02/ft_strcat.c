/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:57:46 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/23 11:05:22 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*#include <stdio.h>
int main()
{
	char	s1[30] = "Buenos días. ";
	char	s2[] = "Como estas?";

	printf("%s\n", ft_strcat(s1, s2));
}*/
