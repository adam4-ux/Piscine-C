#include <stdio.h>
#include <stdlib.h>

int is_sep(char c,char *charset)
{
    int i = 0;
    while(charset[i])
    {
        if(charset[i] == c)
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

    while(str[i])
    {
        while(str[i] && is_sep(str[i],charset))
            i++;

        if(str[i])
        count++;

        while(str[i] && !is_sep(str[i],charset))
            i++;
    }
    return count;
}

char **ft_split(char *str, char *charset)
{
    int i = 0;
    int j;
    int words = count_words(str,charset);
    
    char **arr = malloc((words + 1) * sizeof(char *));

    if(!arr)
    {
        return NULL;
    }
    
    int first = 0;
    int last;     

    while(i < words)
    {
        while(str[first] && is_sep(str[first],charset))
        {
            first ++;
        }
        last = first;
        while(str[last] && !is_sep(str[last],charset))
        {
            last ++;
        }

        arr[i] = malloc((last - first + 1) * sizeof(char));

        if (!arr[i])
        {              
            if(i > 0)
            {
                i--;
                free(arr[i]);
            }
            free(arr);      
            return NULL;
        }
        j = 0;
        while(first < last )
        {
            arr[i][j++] = str[first++];
        }
        arr[i][j] = '\0';
        i++;
    }
    arr[words] = NULL;
    return arr;
}

int main()
{
char str[]     = " Hello ,- world -1337";
char charset[] = " ,-_";

char **result = ft_split(str,charset);
    if (!result)
    return (1);

    
    int i = 0;
    while(result[i])
    {
        printf("%s",result[i]);
        printf("\n");
        i++;
    }
     i = 0;
    while (result[i])
    {
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}

/*
    This picture shows how strings are stored in memory

                        ||
                        ||
                        ||
                        \/

    //C:\Users\adam\Desktop\1337\42books.pdf\ft_split.png
*/
