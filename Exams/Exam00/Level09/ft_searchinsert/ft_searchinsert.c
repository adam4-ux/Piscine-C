#include <stdio.h>
int    ft_searchinsert(int *arr, int n, int target)
{
    int i = 0;
    while(i < n)
    {
        if(arr[i] >= target)
        {
            return i;
        }
        i++;
    }
    return i;
}