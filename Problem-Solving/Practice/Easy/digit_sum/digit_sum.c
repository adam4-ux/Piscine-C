    #include <unistd.h>
    #include <stdio.h>

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

        int nb = atoi(av[1]);
        int sum;

        while(nb >= 10)
        {
            sum = 0;
            while(nb > 0)
            {
                sum = sum + (nb%10);
                nb /= 10;
            }
            nb = sum;
        }
        ft_putnbr(nb);
        ft_putchar('\n');
    }