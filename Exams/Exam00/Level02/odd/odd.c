#include <unistd.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

void ft_putnbr(int nb)
{
    if(nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
        ft_putchar(nb % 10 + '0');
}

int main()
{
    int i = 0;
    while(i <= 10)
    {
        if(i % 2 != 0)
        {
            ft_putnbr(i);
        }
        i++;
    }
    write(1,"\n",1);
}