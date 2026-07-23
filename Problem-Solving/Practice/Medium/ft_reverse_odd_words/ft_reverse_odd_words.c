int is_space(char c)
{ 
    if(c == ' ' || c == '\n' || c == '\t')
    {
        return 1;
    }
    return 0; 
}

void    ft_reverse_odd_words(char *str)
{
    int i;
    int start;
    int end;
    char tmp;

    i = 0;
    while (str[i])
    {
        while(str[i] && is_space(str[i]))
            i++;
        start = i;
        while(str[i] && !is_space(str[i]))
            i++;
        end = i - 1;

        if((end - start + 1) % 2 != 0)
        {
            tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
        }
    }
}