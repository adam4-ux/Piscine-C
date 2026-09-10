#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	show_err(char *operator, int b)
{
	if (operator[1])
	{
		write (1, "0\n", 2);
		return (-1);
	}
	if (b == 0 && operator[0] == '/')
	{
		write (1, "Stop : division by zero\n", 24);
		return (-1);
	}
	if (b == 0 && operator[0] == '%')
	{
		write (1, "Stop : modulo by zero\n", 22);
		return (-1);
	}
	return (1);
}

int	get_index(char *operator, int b)
{
	char	*operators;
	int		i;

	if (show_err(operator, b) == -1)
		return (-1);
	operators = "+-*/%";
	i = 0;
	while (operators[i])
	{
		if (operators[i] == operator[0])
			return (i);
		i++;
	}
	write (1, "0\n", 2);
	return (-1);
}

void	ft_show(char *temp, int i)
{
	while (i >= 0)
	{
		write (1, &temp[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	char	temp[10];

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	i = 0;
	while (nb / 10)
	{
		temp[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	temp[i] = nb + '0';
	ft_show(temp, i);
}
