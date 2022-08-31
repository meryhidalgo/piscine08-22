#include <stdio.h>
char	*ft_strcapitalize(char *str)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (str[i] != 0)
	{
		if (!((64 < str[i] && str[i] < 91) || (96 < str[i] && str[i] < 123)))
		{
			if (!('0' <= str[i] && str[i] <= '9'))
				z = i + 1;
		}
		else if (('a' <= str[i] && str[i] <= 'z') && (z == i))
			str[i] = str[i] - 32;
		else if (('A' <= str[i] && str[i] <= 'Z') && (z != i))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	main()
{
	char	string[]="salut, ComMent tu vas ? 42mots QuaranTe-deux; cinquante+et+un";
	//char	str[]="ho+la m3e llA44M0 5s5i+ ona!aaaaaaaaaaaaaaaaaaaa";
	printf("%s\n", ft_strcapitalize(string));
}
