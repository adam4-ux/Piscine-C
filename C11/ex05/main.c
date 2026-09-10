#include <unistd.h>

int		ft_sum(int a, int b);

int		ft_sub(int a, int b);

int		ft_mul(int a, int b);

int		ft_div(int a, int b);

int		ft_mod(int a, int b);

int		ft_atoi(char *str);

int		show_err(char *operator, int b);

int		get_index(char *operator, int b);

void	ft_show(char *temp, int i);

void	ft_putnbr(int nb);

int	main(int ac, char **av)
{
	int	(*operations[5])(int, int);
	int	a;
	int	b;
	int	index;
	int	result;

	if (ac != 4)
		return (0);
	operations[0] = &ft_sum;
	operations[1] = &ft_sub;
	operations[2] = &ft_mul;
	operations[3] = &ft_div;
	operations[4] = &ft_mod;
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	index = get_index(av[2], b);
	if (index == -1)
		return (0);
	result = operations[index](a, b);
	ft_putnbr(result);
	write (1, "\n", 1);
	return (0);
}
