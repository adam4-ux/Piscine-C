#include <unistd.h>
#include <stdio.h>
int is_space(char c)
{
    if(c == ' ')
    {
        return 1;
    }
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
        {
            i++;
        }
    }
    return count;
}
void    ft_word_reverse_order(char *str)
{
    int words = count_words(str);

    int arr[words];
    int j = 0;

    int first = 0;
    int last;

    while(str[first] == ' ')
        first++;

    while(str[first])
    {
        while(str[first] && is_space(str[first]))
        {
            first++;
        }
        arr[j++] = first;
        last = first;
        while(str[last] && !is_space(str[last]))
        {
            last++;
        }
        first = last;
    }
    
    int i;
    while(words - 1 >= 0)
    {
        i = arr[--j];
        while(str[i] && str[i] != ' ')
        {
            write(1,&str[i],1);
            i++;
        }
        words--;
        if (words > 0)
            write(1, " ", 1);
    }
}