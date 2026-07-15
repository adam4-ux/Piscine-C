#include <unistd.h>

int ft_strcmp(char *s1,char *s2)
{
    int i = 0;
    while(s1[i] && s1[i] == s2[i])
        i++;
    if(s1[i] == s2[i])
        return 0;

    return s1[i] - s2[i];
}

void ft_swap(char **a,char **b)
{
    char *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc,char *argv[])
{
    int i = 0;

    while(i < argc - 1)
    {
        if(ft_strcmp(argv[i],argv[i + 1]) > 0)
        {
            ft_swap(&argv[i],&argv[i+1]);
        }
        i++;
    }
}