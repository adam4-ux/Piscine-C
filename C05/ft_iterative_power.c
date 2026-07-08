/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:13:13 by marvin            #+#    #+#             */
/*   Updated: 2026/04/17 13:13:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    if(power < 0)
    {
        return 0;
    }
    int total = 1;
    while(power > 0)
    {
        total *= nb;
        power--;
    }
}
int main ()
{
    int i = ft_iterative_power(0,0);
    printf("%d",i);
}