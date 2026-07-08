/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eadam <eadam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:08:51 by eadam             #+#    #+#             */
/*   Updated: 2026/06/22 23:11:33 by eadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1 • size is the number of strings in strs
// 2 if size is 0, you must return an empty string that you can free().
//total length = (sum of all string lengths) + (size - 1) * len(sep) + 1   // for '\0'

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s1)
{
    int i = 0;
    while(s1[i])
    {
        i++;
    }
    return i;
}

int ft_total_size(int size, char **strs, char *sep)
{
    int i = 0;
    int total = 0;

    while(i < size)
    {
    //all characters from every string in strs
        total = total + ft_strlen(strs[i]);
        i++;
    }

    //all separator characters between strings
    total = total + (size - 1) * ft_strlen(sep); 
    // Number of separators = size - 1

    return total;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if(size == 0)
    {
        char *ptr = malloc (1);// 1 byte, just for '\0'

        if (!ptr)
            return (NULL);

        ptr[0] = '\0';
        return ptr;
    }

    int total_size = ft_total_size(size,strs,sep);

    char *ptr = malloc(total_size + 1);

    if(!ptr)
    {
        return NULL;
    }

    while(i < size)
    {
        j = 0;
        while(strs[i][j])
        {
            ptr[k++] = strs[i][j];
            j++;
        }
        if(i < size - 1)
        {
            j = 0;
            while(sep[j])
            {
                ptr[k++] = sep[j++];
            }
        }
        i++;
    }
    ptr[k] = '\0';
    
    return ptr;
}
int main()
{
    char *strs[] = {"Hello", "world", "42"};
    char *sep = "-";
    char *result = ft_strjoin(3, strs, sep);

    printf("%s\n",result);
    free(result);
}

/*
    This picture shows how strings are stored in memory

                        ||
                        ||
                        ||
                        \/

    c:\Users\adam\Desktop\1337\42books.pdf\ft_strjoin.png
*/