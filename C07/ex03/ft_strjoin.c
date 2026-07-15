#include <stdlib.h>

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    
    return i;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i = 0;
    int j;
    int len_str = 0;
    int len_sep = ft_strlen(sep);

    while(i < size)
    {
        len_str = len_str + ft_strlen(strs[i]);
        i++;
    }

    char *arr = malloc((len_str + len_sep * (size - 1) + 1 ) * sizeof(char));

    if(!arr)
        return NULL;

    if(size == 0)
    {
        arr[0] = '\0';
        return arr;
    }

    i = 0;
    int k = 0;
    while(i < size)
    {
        j = 0;
        while(strs[i][j])
        {
            arr[k] = strs[i][j];
            k++;
            j++;
        }
        j = 0;
        while(sep[j] && i < size - 1)
        {
            arr[k++] = sep[j++];
        }
        i++;
    }
    arr[k] = '\0';

    return arr;
}