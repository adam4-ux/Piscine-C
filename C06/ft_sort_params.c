/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 14:38:21 by marvin            #+#    #+#             */
/*   Updated: 2026/04/12 14:38:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void ft_swap(char **a, char **b) //
{
    char *tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int ft_strcmp(char *s1,char *s2)
{
    int i = 0;
    while(s1[i] && s1[i] == s2[i])
    {
        i++;
    }
    return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int main(int argc,char *argv[])
{
    int i = 1;
    int j;
    while(i < argc - 1)
    {
        j = i + 1;
        while(j < argc)
        {
            if(ft_strcmp(argv[i],argv[j]) > 0)
            {
                ft_swap(&argv[i],&argv[j]);
            }
            j++;
        }
        i++;
    }

    i = 1;
    int k;
    while(i < argc)
    {
        k = 0;
        while(argv[i][k])
        {
            write(1,&argv[i][k],1);
            k++;
        }
            write(1,"\n",1);
        i++;
    }
}


