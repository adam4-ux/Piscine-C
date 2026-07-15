void ft_rev_int_tab(int *tab, int size)
{
    int first = 0;
    int last = size - 1;
    while(first < size / 2)
    {
        int tmp = tab[first];
        tab[first] = tab[last];
        tab[last] = tmp;
        
        first++;
        last--;
    }
}