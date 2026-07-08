#include <stdio.h>
int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    //while_space
    while(str[i] == 32 || str[i] >= 9 && str[i] <= 13)
    {
        i++;
    }
    //sign
    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            sign *= -1;
        }
        i++;
    }
    //string to int  
    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result*sign;
}
int main()
{
    char str[] = " abc+-+5";
    printf("ft_atoi: %d\n", ft_atoi(str));
}
