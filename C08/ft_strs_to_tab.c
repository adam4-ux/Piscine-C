#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_stock_str.h"

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}

char *ft_strdup(char *str)
{
    int i = 0;
    char *arr = malloc((ft_strlen(str) + 1) * sizeof(char));

    if(!arr)
    {
        return NULL;
    }

    while(str[i])
    {
        arr[i] = str[i];
        i++;
    }
    arr[i] = '\0';

    return arr;
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    int i = 0;
    t_stock_str *arr = malloc((ac + 1) * sizeof(t_stock_str));

    if(!arr)
    {
        return NULL;
    }

    while(i < ac)
    {
        arr[i].size = ft_strlen(av[i]);
        arr[i].str = av[i];
        arr[i].copy = ft_strdup(av[i]);

        if(!arr[i].copy)
        {
            while(i > 0)
            {
                free(arr[--i].copy);
            }
            free(arr);
            return NULL;
        }
        i++;
    }
    arr[i].str = 0;

    return arr;
}

int main(int argc,char *argv[])
{
    t_stock_str *arr = ft_strs_to_tab(argc,argv);

    int i = 0;

    while(arr[i].str)
    {
        write(1,arr[i].copy,arr[i].size);
        write(1,"\n",1);
        i++;
    }
}
//C:\Users\adam\Desktop\1337\42books.pdf\ft_strs_to_tab