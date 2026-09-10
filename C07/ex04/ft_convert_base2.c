#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	invalide_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	idexof_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (idexof_base(str[i], base) != -1)
	{
		result = result * ft_strlen(base) + idexof_base(str[i], base);
		i++;
	}
	return (result * sign);
}

int	count_digits(long nbr, int len)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		count++;
		nbr /= len;
	}
	return (count);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int		len_base;
	int		sign;
	int		digits;
	long	n;
	char	*ptr;

	len_base = ft_strlen(base);
	sign = 0;
	n = nbr;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	digits = count_digits(n, len_base);
	ptr = malloc(digits + sign + 1);
	if (!ptr)
		return (NULL);
	ptr[digits + sign] = '\0';
	while (digits > 0)
	{
		ptr[sign + --digits] = base[n % len_base];
		n /= len_base;
	}
	if (sign)
		ptr[0] = '-';
	return (ptr);
}