#include <unistd.h>
#include <stdlib.h>
int is_space(char c)
{
    if(c == ' ' || c == '\t' || c == '\n')
        return 1;
    return 0;
}
int count_words(char *str)
{
    int i = 0;
    int count = 0;

    while(str[i])
    {
        while(str[i] && is_space(str[i]))   
            i++;

        if(str[i])
            count++;

        while(str[i] && !is_space(str[i]))   
            i++;
    }
    return count;
}

char    **ft_split(char *str)
{
    int words = count_words(str);

    char **arr = malloc((words + 1) * sizeof(char *));

    if(!arr)
        return NULL;

    int i = 0;
    int j;
    int first = 0;
    int last;
    while(i < words)
    {
        while(str[first] && is_space(str[first]))   
            first++;

        last = first;
        while(str[last] && !is_space(str[last]))   
            last++;    

        arr[i] = malloc((last-first+1) * sizeof(char));

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
        while(first < last)
        {
            arr[i][j++] = str[first++];
        }

        arr[i][j] = '\0';
        i++;
    }
    arr[words] = NULL;

    return arr; 
}