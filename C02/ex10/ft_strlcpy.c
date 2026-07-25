int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i = 0;
    unsigned int len = ft_strlen(src);

    if(size == 0)
        return len;
        
    while(i < size - 1 && src[i])
    {
        dest[i] = src[i];
        i++;
    }
        dest[i] = '\0';
    return len;
}