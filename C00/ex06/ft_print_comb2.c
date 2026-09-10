#include <unistd.h>

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	x1;
	char	x2;
	char	x3;
	char	x4;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			x1 = i / 10 + '0';
			x2 = i % 10 + '0';
			x3 = j / 10 + '0';
			x4 = j % 10 + '0';
			write(1, &x1, 1);
			write(1, &x2, 1);
			write(1, " ", 1);
			write(1, &x3, 1);
			write(1, &x4, 1);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}