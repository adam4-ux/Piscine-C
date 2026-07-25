void ft_swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void ft_sort_int_tab(int *tab, int size)
{
    int i = 0;
    int j;
    while(i < size - 1)
    {
        j = i + 1;
        while(j < size)
        {
            if(tab[i] > tab[j])
            {
                ft_swap(&tab[i],&tab[j]);
            }
            j++;
        }
        i++;
    }
}