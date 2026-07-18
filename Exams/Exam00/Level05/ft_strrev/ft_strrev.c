int    ft_strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    return (i);
}

char    *ft_strrev(char *str)
{
    int i = 0;
    int len = ft_strlen(str) - 1;
    char tmp;

    while (i < len)
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
        len--;
    }
    return (str);
}