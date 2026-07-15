#include <stdio.h>
int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
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
        if(base[i] == '+' || base[i] == '-'
            || base[i] == ' '
            || (base[i] >= 9 && base[i] <= 13))
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

int indexof_base(char str,char *base)
{
    int i = 0;
    while(base[i])
    {
        if(str == base[i])
        {
            return i;
        }
        i++;
    }
    return -1;
}

int ft_atoi_base(char *str, char *base)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    int len_base = ft_strlen(base);

    if(!(invalid_base(base)))
        return 0;

    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;

    while (str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            sign *= -1;
        }
        i++;
    }

    while(indexof_base(str[i],base) != -1)
    {
        result = result * len_base + indexof_base(str[i],base);
        i++;
    }
    return result*sign;
}