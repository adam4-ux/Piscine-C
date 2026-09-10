#include <unistd.h>

void	print_address(unsigned long long addr)
{
	char	*hex;
	char	str[16];
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		str[i] = hex[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, str, 16);
	write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*hex;
	unsigned char	*str;
	unsigned int	i;
	unsigned int	j;

	hex = "0123456789abcdef";
	str = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_address((unsigned long long)&str[i]);
		j = 0;
		while (j < 16)
		{
			if (i + j < size)
			{
				write(1, &hex[str[i + j] / 16], 1);
				write(1, &hex[str[i + j] % 16], 1);
			}
			else
				write(1, "  ", 2);
			if (j % 2 != 0)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (str[i + j] >= 32 && str[i + j] < 127)
				write(1, &str[i + j], 1);
			else
				write(1, ".", 1);
			j++;
		}
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}