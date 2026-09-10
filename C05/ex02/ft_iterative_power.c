int	ft_iterative_power(int nb, int power)
{
	int	count;

	count = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		count *= nb;
		power--;
	}
	return (count);
}