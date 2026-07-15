char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    unsigned int i = 0;
    while(dest[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return dest;
}