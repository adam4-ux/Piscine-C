#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *s1)
{
    int i = 0;
    while(s1[i])
    {
        i++;
    }
    return i;
}
char *ft_strdup(char *src)
{
    int i = 0;
    int len = ft_strlen(src);
    char *copy = malloc(len * sizeof(char));

    if(copy == NULL)
    {
        return NULL;
    }

    while(src[i])
    {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';

    return copy;
}

int main()
{
    char *s= ft_strdup("Adam");

    printf("%s\n",s);
} 