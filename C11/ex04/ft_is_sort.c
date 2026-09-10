int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sa;
	int	sd;

	if (length <= 1)
		return (1);
	i = 0;
	sa = 1;
	sd = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			sa = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			sd = 0;
		i++;
	}
	return (sa || sd);
}
