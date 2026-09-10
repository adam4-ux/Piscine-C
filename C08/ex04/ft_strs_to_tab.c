#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*arr;

	i = 0;
	len = ft_strlen(src);
	arr = malloc((len + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ptr;
	int			i;

	ptr = malloc((ac + 1) * sizeof(t_stock_str));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ptr[i].size = ft_strlen(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = ft_strdup(av[i]);
		if (!ptr[i].copy)
		{
			while (i > 0)
				free(ptr[--i].copy);
			free(ptr);
			return (NULL);
		}
		i++;
	}
	ptr[ac].size = 0;
	ptr[ac].str = NULL;
	ptr[ac].copy = NULL;
	return (ptr);
}