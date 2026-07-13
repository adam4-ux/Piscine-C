int ft_sqrt(int nb)
{
    int i;
    if(nb < 0)
        return 0;

    i = 1;
    while(i <= nb / i)
    {
        if(i * i == nb)
            return i;
        i++;
    }
    return 0;
}