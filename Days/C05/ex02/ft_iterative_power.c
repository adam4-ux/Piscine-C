int ft_iterative_power(int nb, int power)
{
    int count = 1;

    if(power < 0)
        return 0;
    if(power == 0)
        return 1;
    if(power == 1)
        return nb;

    while(power > 0)
    {
        count *= nb;
        power--;
    }
    return count;
}