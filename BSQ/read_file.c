/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarazo- <mcarazo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:40:34 by mcarazo-          #+#    #+#             */
/*   Updated: 2022/08/31 12:08:03 by mcarazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_stdin(void)
{
	char	c;
	int		fd;

	fd = open("stdin.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (read(0, &c, 1) != 0)
		write (fd, &c, 1);
	close(fd);
}

int	size_dict(char *filename)
{
	int		fd;
	char	c;
	int		size;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		exit (0);
	}
	else
	{
		while (read(fd, &c, 1) != 0)
			size++;
	}
	close (fd);
	return (size);
}

char	*array_dict(int size, char *filename)
{
	char	*array_dict;
	int		fd;

	array_dict = (char *)malloc(sizeof(char) * (size + 1));
	fd = open(filename, O_RDONLY);
	read (fd, array_dict, size);
	close (fd);
	return (array_dict);
}
