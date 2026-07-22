#include <unistd.h>

void    ft_remove_duplicates(char *str)
{
    int i;
    int j;
    int k;
    int duplicate;

    i = 0;
    k = 0;
    while (str[i])
    {
        duplicate = 0;
        j = 0;
        while (j < i)
        {
            if (str[i] == str[j])
                duplicate = 1;
            j++;
        }
        if (duplicate == 0)
        {
            str[k] = str[i];
            k++;
        }
        i++;
    }
    str[k] = '\0';
}