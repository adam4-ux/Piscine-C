#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }   
    return i;
}

int invalid_base(char *base)
{
    int i = 0;
    int j;
    
    if(ft_strlen(base) < 2)
        return 0;
    
    while(base[i])
    {
        if((base[i] == 32)||(base[i] >= 9 && base[i] <= 13)||(base[i] == '+' || base[i] == '-'))
              return 0;
        
        j = i + 1;
        while(base[j])
        {
            if(base[i] == base[j])
                return 0;

            j++;
        }
        i++;
    }
    return 1;
}

int indexof_base(char c,char *base)
{
    int i = 0;
    while(base[i])
    {
        if(base[i] == c)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int atoi_base(char *nbr,char *base_from)
{
    int i=0;
    int result = 0;
    int base_len = ft_strlen(base_from);
    int sign = 1;
    
    while((nbr[i] == 32) || (nbr[i] >= 9 && nbr[i] <= 13))
    {
        i++;
    }

    while(nbr[i] == '+' || nbr[i] == '-')
    {
        if (nbr[i] == '-')
            sign *= -1;
        i++;
    }

    while(nbr[i])
    {
        int digit = indexof_base(nbr[i],base_from);

            if (digit == -1)
                break;
        result = result * base_len + digit;
        i++;
    }
    return result*sign;
}

int count_digit(int nbr,int base_len)
{
    int count = 0;
    if (nbr == 0)
        return (1);
    if (nbr < 0)
        nbr = -nbr;

    while(nbr > 0)
    {
            count++;
        nbr /= base_len;
    }
    return count;
}

char *putnbr_base(int nbr,char *base_to)
{
    int i = 0;
    int sign = 0;
    int base_len = ft_strlen(base_to);
    int len = count_digit(nbr,base_len);
    
    if (nbr < 0)
    {
        sign = 1;
        nbr = -nbr;
    }
    char *ptr = malloc(len + sign + 1);
    if(!ptr)
    {
        return NULL;
    }

    ptr[len+sign] = '\0';
    while(len > 0)
    {
        ptr[sign + --len] = base_to[nbr % base_len];
        nbr /= base_len;
    }
    if(sign == 1)
        ptr[0] = '-';

    return ptr;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    if(!(invalid_base(base_from) && invalid_base(base_to)))
        return NULL;

    int value = atoi_base(nbr,base_from);
    char *result = putnbr_base(value,base_to);

    return result;
}
int main()
{
char *res5  = ft_convert_base("000123", "0123456789", "0123456789ABCDEF");//7B
char *res6  = ft_convert_base("-0", "0123456789", "0123456789");//0
char *res7  = ft_convert_base("+-+5", "0123456789", "0123456789ABCDEF");//-5
char *res8  = ft_convert_base("7FFFFFFF", "0123456789ABCDEF", "0123456789");//2147483647
char *res9  = ft_convert_base("5", "0123456789", "01");//101
char *res10 = ft_convert_base("10", "0123456789", "ZYXWVUTSRQ");//YZ

printf("%s\n", res5);
printf("%s\n", res6);
printf("%s\n", res7);
printf("%s\n", res8);
printf("%s\n", res9);
printf("%s\n", res10);

free(res5);
free(res6);
free(res7);
free(res8);
free(res9);
free(res10);
}