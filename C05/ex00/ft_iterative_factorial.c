int ft_iterative_factorial(int nb)
{
    int count = 1;
    if(nb < 0)
        return 0;
    
    while(nb > 0)
    {
        count = count * nb;
        nb--;
    }
    return count;
}