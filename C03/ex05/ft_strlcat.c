unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int dest_len = 0; 
    unsigned int src_len = 0;
    unsigned int i = 0;

    while(dest[dest_len])
        dest_len++;

    while (src[src_len])
        src_len++;

    if(size <= dest_len)
        return (size + src_len);
    
    while(src[i]  && (dest_len + i) < (size - 1))
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';

    return (dest_len + src_len);
}