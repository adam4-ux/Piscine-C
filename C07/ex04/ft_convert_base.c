#include <stdlib.h>
#include <stdio.h>

int invalide_base(char *base);
int ft_atoi_base(char *str, char *base);
char *ft_itoa_base(int nbr, char *base);

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    if(invalide_base(base_from) || invalide_base(base_to))
    {
        return NULL;
    }
    int value = ft_atoi_base(nbr, base_from);
    char *result = ft_itoa_base(value, base_to);

    return result;
}