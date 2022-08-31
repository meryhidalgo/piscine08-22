
int	atoi (char *z) //Recoge puntero para poder editar su valor. 
{
	int	i;
	int	m;
	int	r;
	int	h;

	i = 0;
	m = 1;
	r = 0;
	while (z[i] >= 48 && z[i] <= 57)
		i++;
	while (i > 0)
	{
		h = z[i - 1] + 48;
		r += m * h;
		m *= 10;
		i--;
	}
	return (r); //Me devuelve un entero. 
}
