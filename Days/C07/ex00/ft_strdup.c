#include <stdlib.h>
int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}
char *ft_strdup(char *src)
{
    int i = 0;
    int len = ft_strlen(src);

    char *arr = malloc((len + 1) * sizeof(char));

    if(!arr)
        return NULL;

    while (src[i])
    {
        arr[i] = src[i];
        i++;
    }
    arr[i] = '\0';
    return arr;
}