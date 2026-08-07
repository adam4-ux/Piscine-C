// Assignment name  : two_sum
// Expected files   : two_sum.c
// Allowed functions: malloc

// --------------------------------------------------------------------------------

// Write a function that returns the indices of the two numbers whose sum
// is equal to target.

// You may assume that:
// - There is exactly one solution.
// - You may not use the same element twice.
// - The returned array must be allocated with malloc.

// Prototype:

// int *two_sum(int *nums, int numsSize, int target);

// input : num[2,7,11,15]
// output : [0,1]

#include <unistd.h>
#include <stdio.h>
int *two_sum(int *nums, int numsSize, int target)
{
    int *arr = malloc(sizeof(int) * 2);

    int i = 0;
    while (i < numsSize)
    {
        int j = i + 1;
        while (j < numsSize)
        {
            if (nums[i] + nums[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
                return (arr);
            }
            j++;
        }
        i++;
    }
}
