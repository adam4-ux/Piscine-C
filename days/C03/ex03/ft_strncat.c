char *ft_strncat(char *dest, char *src, unsigned int nb)
{
   unsigned int i = 0;
   unsigned int j = 0; 
    while(dest[i])
        i++;
    while(src[j]  && j < nb)
        dest[i++] = src[j++];

    dest[i] = '\0';

    return dest;
}