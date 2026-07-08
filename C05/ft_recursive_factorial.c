/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:50:37 by marvin            #+#    #+#             */
/*   Updated: 2026/04/17 11:50:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_recursive_factorial(int nb)
{
    if(nb < 0)
        return 0;
    if(nb == 1)
        return 1;

    else
        return nb * ft_recursive_factorial(nb - 1);
}

int main()
{
    int i =  ft_recursive_factorial(-5);
    printf("%d",i);
}