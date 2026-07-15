void ft_ultimate_div_mod(int *a, int *b)
{
    int old_a  = *a;
    *a = *a / *b;
    *b = old_a  % *b;
}