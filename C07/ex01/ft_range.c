#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	range;
	int	*arr;

	i = 0;
	range = max - min;
	if (min >= max)
		return (NULL);
	arr = malloc(range * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < range)
	{
		arr[i] = min++;
		i++;
	}
	return (arr);
}