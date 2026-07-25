#include <unistd.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putnbr(int nb)
{
    if(nb < 0)
    {
        write(1,"-",1);
        nb = -nb;
    }

    if(nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
        ft_putchar(nb % 10 + '0');
}

void    ft_man_subarray(int *arr, int n)
{
    int i = 0;
    int j;
    int max = arr[0];
    int current;

    while(i < n)
    {
        j =  j + 1;
        current = 0;
        while (j < n)
        {
            current = current + arr[j];

            if(current > max)
            {
                max = current ;
            }
            j++;
        }
        i++;
    }
    ft_putnbr(max);
}