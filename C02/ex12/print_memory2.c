#include <stdio.h>
void	*ft_print_memory(void *addr, unsigned int size)
{
	(int *)addr; 

	return (addr);
}

int	main()
{
	int	*variable;
	
	printf("%p\n", variable);
	printf("%p\n", ft_print_memory((void *)variable, sizeof(variable)));
}
