// Assignment name  : ft_searchinsert
// Expected files   : ft_searchinsert.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that searches for a target value in a sorted integer array.

// If the target is found, the function must return its index.

// If the target is not found, the function must return the index where it
// should be inserted in order to keep the array sorted.

// The array contains n elements sorted in ascending order.

// It should be prototyped as such

// int    ft_searchinsert(int *arr, int n, int target);
// ==========================================================================================

#include <unistd.h>
#include <stdio.h>

int    ft_searchinsert(int *arr, int n, int target)
{
    if(n <= 0)
    {
        return 0;
    }
    int i = 0;
    int result = 0;
    while (i < n)
    {
        if (arr[i] >= target)
            return (i);
        i++;
    }
    return (n);

}
int main()
{
    int arr[] = {0,2,4,6,7};
    int i = ft_searchinsert(arr,5,4);

    printf("%d\n",i);

}