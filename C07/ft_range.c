#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    if(min >= max)
    {
        return NULL;
    }

    int *range = malloc((max-min) * sizeof(int));
    
    if(range == NULL)
    {
        return NULL;
    }

    int i = 0;
    while(min < max)
    {
        range[i++] = min;
        min++;
    }

    return range;
}
int main()
{
    int max = 2;
    int min = -2;
    int *range = ft_range(-2,2);

    int i = 0;
    int end = max - min;
    while(i < end)
    {
        printf("%d \n",range[i]);
        i++;
    }
        free(range);
}