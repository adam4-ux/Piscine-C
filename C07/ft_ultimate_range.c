#include <stdio.h>
#include <stdlib.h>

// **range = first value of array
int ft_ultimate_range(int **range, int min, int max)
{
    int i = 0;
    int size;

    if(min >= max)
    {
        *range = NULL;
        return 0;
    }
    size = max- min;
    int *tab = malloc(size * sizeof(int));
    
    if(tab == NULL)
    {
        return -1;
    }

// *range = tab itsel
    *range = tab;

    while(i < size)
    {
        tab[i++] = min++;
    }

    return size;
}
int main()
{
    int *tab ;
    int min = 1;
    int max = 100;
    int size = ft_ultimate_range(&tab,min,max);

    printf("%d\n",size);

    for (int i = 0; tab[i]; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");

}