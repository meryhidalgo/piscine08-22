/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:08:26 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/23 11:08:30 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				len1;
	unsigned int	i;

	i = 0;
	len1 = 0;
	while (dest[len1] != 0)
		len1++;
	while (src[i] != 0 && i < nb)
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
	char	s1[30] = "Buenos días";
	char	s2[] = "Comoestas?";

	printf("%s\n", ft_strncat(s1, s2, 5));
}*/
