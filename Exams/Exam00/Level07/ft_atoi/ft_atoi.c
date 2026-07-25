int     ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
    {
        i++;
    }

    if(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result *  10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}