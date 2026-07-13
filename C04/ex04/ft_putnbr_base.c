#include <unistd.h>
#include <limits.h>

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;

    return i;
}

int invalid_base(char *base)
{
    int i = 0;
    int j;
    if(base[0] == '\0' || base[1] == '\0')
        return 0;
    while(base[i])
    {
        if(base[i] == '+' || base[i] == '-')
        {
            return 0;
        }
            j = i + 1;
            while(base[j])
            {
                if(base[i] == base[j])
                {
                    return 0;
                }
                j++;
            }
        i++;
    }
    return 1;
}

void ft_putnbr_base(int nbr, char *base)
{
    int base_len = ft_strlen(base);
    long n = nbr;

    if(!(invalid_base(base)))
        return;

    if(n < 0)
    {
        write(1,"-",1);
        n = -n;
    }

    if(n >= base_len)
    {
        ft_putnbr_base(n / base_len , base);
    }
        write(1,&base[n % base_len],1);
}