/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:05:52 by marvin            #+#    #+#             */
/*   Updated: 2026/04/20 13:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int ft_prime(int nb)
{
    int i = 2;
        while(i * i <= nb)
        {
            if(nb % i == 0)
            {
                return 0;
            }
            i++;
        }
    return 1;
}
int ft_find_next_prime(int nb)
{
    if(nb <= 1)
        return 2;

    while(ft_prime(nb) == 0)
    {
        nb++;
    }
    return nb;
}
int main()
{
    int i = ft_find_next_prime(14);
    printf("%d",i);
}