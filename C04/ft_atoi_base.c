/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:05:26 by eadam             #+#    #+#             */
/*   Updated: 2026/06/18 12:32:37 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}

int invalid_base(char *base)
{
    int i = 0;
    int j;
    
    if(base[0] == '\0' || base[1] == '\0')
    {
        return 0;
    }
    while(base[i])
    {
        if(base[i] == 32 
            || base[i] >= 9 && base[i] <= 13 
            || base[i] == '+' 
            || base[i] == '-')
            {
                return 0;
            }
        j = i + 1;
        while(base[j])
        {
            if(base[i] == base[j])
            {
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}

int indexof_base(char c,char *base)
{
    int i = 0;
    while(base[i])
    {
        if(base[i] == c)
        {
            return i;
        }
        i++;
    }
    return 0;
}

int check_base(char c,char *base)
{
    int i = 0;
    while(base[i])
    {
        if(base[i] == c)
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int ft_atoi_base(char *str, char *base)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    if(!(invalid_base(base)))
    {
        return 0;
    }

    while(str[i] == 32 || str[i] >= 9 && str[i] <= 13)
    {
        i++;
    }

    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
        {
            sign *= -1;
        }
        i++;
    }

    while(check_base(str[i],base))
    {
        result = result * ft_strlen(base) + indexof_base(str[i],base);
        i++;    
    }

    return result*sign;
}

int main()
{
printf("%d\n", ft_atoi_base("-+2A", "0123456789ABDEF"));
printf("%d\n", ft_atoi_base("1010", "01"));
printf("%d\n", ft_atoi_base("5", "a"));
}