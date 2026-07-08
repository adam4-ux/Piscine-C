/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:32:36 by marvin            #+#    #+#             */
/*   Updated: 2026/03/23 16:32:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
    {
        i++;
    }
    return i;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    int len_src = ft_strlen(src);
    int len_dest = ft_strlen(dest);

    unsigned int i = 0;

    if(size <=  len_dest)
        return len_src + size;

    while(len_dest + i < size - 1 && src[i])
    {
        dest[len_dest + i] = src[i];
        i++;
    }
    dest[len_dest + i] = '\0';

    return len_dest + len_src;
}

int main()
{
    char dest[30] = "adam ";
    char src[] = "eddoukkali";

    int len = ft_strlcat(dest,src,5);
    printf("%s\n",dest);
    printf("%d",len);
    return 0;
}