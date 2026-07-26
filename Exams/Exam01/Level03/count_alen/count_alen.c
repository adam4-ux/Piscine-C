int    count_alen(char *str)
{
    int count = 0;
    int i = 0;
    while(str[i])
    {
        if(str[i] == 'a')
        {
            count++;
        }
        i++;
    }
    return count;
}