#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	size_dict(void)
{
	int		fd;
	char	c;
	int		size;

	size = 0;
	fd = open("./numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		write (1, "Error\n", 6);
		return (-1);
	}
	else
	{
		while (read(fd, &c, 1) != 0)
			size++;
	}
	close (fd);
	return (size);
}

char	*array_dict(int size)
{
	char	*array_dict;
	int		fd;

	array_dict = (char *)malloc(sizeof(char)* size); // a lo mejor +1
	fd = open("./numbers.dict", O_RDONLY);
	read (fd, array_dict, size);
	close (fd);
	return (array_dict);
}

int	main(void)
{
	printf("%d\n", size_dict());
	printf("%s", array_dict(size_dict()));
}
