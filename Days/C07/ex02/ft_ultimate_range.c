#include <stdlib.h>
int ft_ultimate_range(int **range, int min, int max)
{
    int i = 0;
    int diff  = max - min;

    if(min >= max)
    {
        *range = NULL;
        return 0;
    }

    *range = malloc(diff  * sizeof(int));
    if(! *range)
        return -1;

    while(i < diff)
    {
        (*range)[i] = min++;
        i++;
    }

    return diff;
}