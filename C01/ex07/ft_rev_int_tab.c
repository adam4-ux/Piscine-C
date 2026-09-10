void	ft_rev_int_tab(int *tab, int size)
{
	int	first;
	int	last;
	int	tmp;

	first = 0;
	last = size - 1;
	while (first < size / 2)
	{
		tmp = tab[first];
		tab[first] = tab[last];
		tab[last] = tmp;
		first++;
		last--;
	}
}