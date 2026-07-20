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

void    pingpong(int n)
{
    if((n % 3 == 0) && (n % 5 == 0))
        write(1,"pingpong\n",9);
    else if((n % 3 == 0))
        write(1,"ping\n",5);
    else if((n % 5 == 0))
        write(1,"pong\n",5);
    else
    {
        ft_putnbr(n);
        write(1,"\n",1);
    }
}