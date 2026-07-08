#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void ft_putnbr(int nb)
{
    char c;

    if (nb >= 10)
        ft_putnbr(nb / 10);
    c = (nb % 10) + '0';
    write(1, &c, 1);
}

void ft_show_tab(struct s_stock_str *par)
{
    int i;

    i = 0;
    while (par[i].str)
    {
        write(1, par[i].str, par[i].size);
        write(1, "\n", 1);
        ft_putnbr(par[i].size);
        write(1, "\n", 1);
        write(1, par[i].copy, par[i].size);
        write(1, "\n", 1);
        i++;
    }
}