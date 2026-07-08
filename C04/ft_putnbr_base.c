#include <unistd.h>
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}

int is_valid_base(int nbr1, char *base1)
{
    int len = ft_strlen(base1);

    int i = 0;
    int j;

    if(len < 2)
        return 1;
    
    while(base1[i])
    {
        if(base1[i] == '+' || base1[i] == '-')
            return 1;
        j = i + 1;
        while(j <= len)
        {
            if(base1[i] == base1[j])
            {
                return 1;
            }
            j++;
        }
        i++;
    }
}

void ft_putnbr_base(int nbr, char *base)
{
    int len = ft_strlen(base);
    if(is_valid_base(nbr,base) == 1)
    {
        return;
    }

    long num = nbr; //We use 'long' because 'int' cannot handle -INT_MIN safely
    if(num < 0)
    {
        write(1,"-",1);
        num = -num;
    }

    if (num >= len)//the number has more than one digit in this base like 42 >= 2
        ft_putnbr_base(num / len, base);
    write(1, &base[num % len], 1);
}
int main()
{
ft_putnbr_base(42, "");           // Output: nothing
ft_putnbr_base(42, "0");          // Output: nothing
ft_putnbr_base(42, "01234+5");    // Output: nothing (invalid character)
ft_putnbr_base(42, "1123");       // Output: nothing (duplicate characters)
    return 0 ;
}