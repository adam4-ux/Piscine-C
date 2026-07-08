/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:55:16 by marvin            #+#    #+#             */
/*   Updated: 2026/04/18 11:55:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_recursive_power(int nb, int power)
{
    if(power < 0)
        return 0;
    if(power == 0)
        return 1;
    else
        return nb * ft_recursive_power(nb,power-1);
}
int main ()
{
    int i = ft_recursive_power(-5,3);
    printf("%d",i);
}