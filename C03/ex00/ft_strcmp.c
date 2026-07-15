int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while(s2[i] && s1[i] == s2[i])
        i++;

    if(s1[i] == s2[i])
        return 0;

    return s1[i] - s2[i];
}