#include <unistd.h>
int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}

char    *ft_collapse_spaces(char *str)
{
    int i = 0;
    int len = ft_strlen(str);
    char copy[len];
    int j = 0;

    while((str[i] == ' '))
    {
        i++;
    }
    while(str[i])
    {
        if(str[i] != ' ')
        {
            copy[j++] = str[i];
        }

        else if(str[i+1] != ' ' && str[i+1] != '\0')
        {
            copy[j++] = ' ';
        }
        i++;
    }
    copy[j] = '\0';
    
    i = 0;
    while (copy[i])
    {
        str[i] = copy[i];
        i++;
    }   
    str[i] = '\0';
    return str;
}

int	main(void)
{
	char	str[] = "   hello    world               ";
	char	*result;

	result = ft_collapse_spaces(str);
	write(1, result, ft_strlen(result));
	write(1, "\n", 1);
}