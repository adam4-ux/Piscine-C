/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:05:46 by marvin            #+#    #+#             */
/*   Updated: 2026/04/18 12:05:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int ft_fibonacci(int index)
{
    if(index < 0)
        return -1;
    if(index == 0)
        return 0;
    if(index == 1)
        return 1;
    else 
        return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}
int main()
{
    int i = ft_fibonacci(8);
    printf("%d",i);
}