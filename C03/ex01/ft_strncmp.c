/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:57:29 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/24 17:28:10 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>
int	main ()
{
	char			string1[] = "Buenos dia";
	char			string2[] = "Buenos dias";
	unsigned int	n = 30;

	printf("%d\n", ft_strncmp(string1, string2, n));
	printf("%d\n", strncmp(string1, string2, n));
}*/
