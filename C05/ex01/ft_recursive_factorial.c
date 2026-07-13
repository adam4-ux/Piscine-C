int ft_recursive_factorial(int nb)
{
    int count = 1;
    if(nb < 0)
        return 0;
    if(nb == 0)
        return count;

    count = nb * ft_recursive_factorial(nb-1);
    return count;
}