#include <unistd.h>
int main(int argc, char *argv[])
{
	int i;

	i = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
			argv[1][i] = argv[1][i] + 13;
		write(1, &argv[1][i], 1);
		i++;
	}
}
