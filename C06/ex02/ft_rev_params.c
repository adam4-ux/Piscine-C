#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	ac;
	int	i;

	ac = argc - 1;
	while (ac >= 1)
	{
		i = 0;
		while (argv[ac][i])
		{
			write(1, &argv[ac][i], 1);
			i++;
		}
		write(1, "\n", 1);
		ac--;
	}
}