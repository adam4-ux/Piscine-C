#include <unistd.h>

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;
	char	xa;
	char	xb;
	char	xc;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				xa = a + '0';
				xb = b + '0';
				xc = c + '0';
				write(1, &xa, 1);
				write(1, &xb, 1);
				write(1, &xc, 1);
				if (a != 7)
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}