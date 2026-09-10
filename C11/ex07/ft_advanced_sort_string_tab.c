void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int		skip;
	int		i;

	if (!tab)
		return ;
	skip = 1;
	while (skip)
	{
		i = 1;
		skip = 0;
		while (tab[i])
		{
			if (cmp(tab[i - 1], tab[i]) > 0)
			{
				temp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = temp;
				skip = 1;
			}
			i++;
		}
	}
}
