/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:51:31 by marvin            #+#    #+#             */
/*   Updated: 2026/04/18 12:51:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int ft_is_prime(int nb)
{
    if(nb <= 1)
        return 0;
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
int main()
{
    int i = ft_is_prime(13);
    printf("%d",i);
}