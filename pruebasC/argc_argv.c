#include <unistd.h>

int		main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "b", 1);
	else
	{
		while (*argv[1] != '\0')
		{
			if (*argv[1] == 'a')
			{
				write(1, "\na", 2);
				break;
			}
			write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
