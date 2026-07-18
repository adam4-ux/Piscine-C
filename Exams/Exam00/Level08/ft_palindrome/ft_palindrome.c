int    ft_size(int nb)
{
    int count;

    count = 0;
    while (nb > 0)
    {
        count++;
        nb /= 10;
    }
    return (count);
}

int    ft_palindrome(int n)
{
    int i;
    int size;
    int len;
    int arr[10];
    int nb;

    if (n < 0)
        return (0);

    if (n == 0)
        return (1);

    i = 0;
    size = ft_size(n);
    len = size - 1;
    nb = n;

    while (nb > 0)
    {
        arr[i] = nb % 10;
        nb /= 10;
        i++;
    }

    i = 0;
    while (i < size / 2)
    {
        if (arr[i] != arr[len])
            return (0);
        i++;
        len--;
    }
    return (1);
}