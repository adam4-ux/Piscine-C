#include <stdio.h>
#include <stdlib.h>

int is_separator(char c,char *sep)
{
    int i = 0;
    while(sep[i])
    {
        if(c == sep[i])
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int count_words(char *str,char *charset)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        while(str[i] && is_separator(str[i],charset))
            i++;

        if(str[i])
            count++;

        while(str[i] && !is_separator(str[i],charset))
            i++;     
    }
    return count;
}

char **ft_split(char *str, char *charset)
{
    int i = 0;
    int j;
    int word = count_words(str,charset);

    char **arr = malloc((word + 1) * sizeof(char*));
    if(!arr)
        return NULL;

    int start = 0;
    int end;

    while(i < word)
    {
        while(str[start] && is_separator(str[start],charset))
            start++;

        end = start;

        while(str[end] && !is_separator(str[end],charset))
           end++; 

        arr[i] = malloc((end - start + 1) * sizeof(char));
        if(!arr[i])
        {
            while(i > 0)
            {
                free(arr[--i]);
            }
            free(arr);
            return NULL;
        }

        j = 0;
        while(start < end)
            arr[i][j++] = str[start++];

        arr[i][j] = '\0';
        i++;
    }
        arr[word] = NULL;

    return arr;
}