#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1,&c,1);
}

long atoi(char *str)
{
    long i = 0;
    long result = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

void base_16(long nb)
{
    char hex[16] = "0123456789ABCDEF";
    if(nb >= 16)
    {
        base_16(nb / 16);
    }
        ft_putchar(hex[nb % 16]);    
}

int main(int ac,char *av[])
{
    if(ac != 2)
    {
        write(1,"\n",1);
        return 0;
    }
    long nb;
    nb =  atoi(av[1]);
    base_16(nb);
    write(1,"\n",1);
}