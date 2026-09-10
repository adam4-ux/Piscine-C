#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!ft_is_charset(*str, charset))
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		str++;
	}
	return (count);
}

int	ft_wrod_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !ft_is_charset(str[len], charset))
		len++;
	return (len);
}

char	*ft_get_word(char *str, int len)
{
	int		i;
	char	*word;

	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		count;
	int		len;
	int		i;

	count = ft_count_word(str, charset);
	strs = malloc((count + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!ft_is_charset(*str, charset))
		{
			len = ft_wrod_len(str, charset);
			strs[i] = ft_get_word(str, len);
			i++;
			str += len;
		}
		else
			str++;
	}
	strs[i] = NULL;
	return (strs);
}
