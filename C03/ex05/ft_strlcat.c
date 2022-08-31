/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:14:03 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/24 17:31:16 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length_dest;
	unsigned int	length_src;

	i = 0;
	length_dest = 0;
	length_src = 0;
	while (src[length_src] != 0)
		length_src++;
	while (dest[length_dest] != 0)
		length_dest++;
	if (size == 0 || size <= length_dest)
		return (length_src + size);
	while (src[i] != 0 && i < (size - length_dest - 1))
	{
		dest[length_dest + i] = src[i];
		i++;
	}
	dest[length_dest + i] = 0;
	return (length_src + length_dest);
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	char	dest[30] = "hola";
	char	src[] = "buenos dias";
	char	dest2[30] = "hola";
	char	src2[] = "buenos dias";
	int		n = 4;

	printf("%d\n", ft_strlcat(dest, src, n));
	printf("%s\n", dest);
	printf("%lu\n", strlcat(dest2, src2, n));
	printf("%s\n", dest2);
}*/
