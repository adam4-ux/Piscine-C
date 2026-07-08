/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:14:48 by marvin            #+#    #+#             */
/*   Updated: 2026/03/23 16:14:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char *ft_strstr(char *str, char *to_find)
{
    int i = 0;
    int j;
    int len = ft_strlen(str) - ft_strlen(to_find);

    while(i <= len)
    {
        j = 0;
        while(to_find[j] && str[i + j] == to_find[j])
        {
            j++;
        }
        if(j == ft_strlen(to_find))
        {
            return &str[i];
        }
        i++;
    }
    return NULL;
}
int main()
{
    char str[150] = "all those problems are not important , because the goal of my, success in the best coding schole in morocco";
    char to_find[] = "success";

    char *len = ft_strstr(str,to_find);

    int i = 0;
    while(len[i])
    {
        write(1,&len[i],1);
        i++;
    }
    return 0;
}