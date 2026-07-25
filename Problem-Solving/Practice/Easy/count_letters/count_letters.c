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

int main(int ac,char *av[])
{
    if(ac != 2)
    {
        write(1,"\n",1);
        return 0;
    }
    int i = 0;
    int count = 0;
    while(av[1][i])
    {
        if((av[1][i] >= 'a' && av[1][i] <= 'z') || (av[1][i] >= 'A' && av[1][i] <= 'Z'))
        {
            count++;
        }
        i++;
    }
    ft_putnbr(count);
    ft_putchar('\n');

}