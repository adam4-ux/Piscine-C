#include <stdlib.h>
int *ft_range(int min, int max)
{
    int i = 0;
    int range = max-min;

    if(min >= max)
        return NULL;

    int *arr = malloc(range * sizeof(int));
    if(!arr)
        return NULL;


    while(i <= range)
    {
        arr[i] = min++;
        i++;
    }

    return arr;
}