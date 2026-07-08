/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:10:51 by marvin            #+#    #+#             */
/*   Updated: 2026/04/17 11:10:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int ft_iterative_factorial(int nb)
{
    int total = 1; 
    if(nb < 0)
        return 0;

    while(nb > 0)
    {
        total = total * nb--;
    }
    return total;
}
int main ()
{
    int i = ft_iterative_factorial(10);
    printf("%d",i);
}