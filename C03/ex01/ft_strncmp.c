int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i = 0;
    if(n <= 0)
        return 0;

    while(s1[i] && s1[i] == s2[i] && i < n - 1)
        i++;

    if(s1[i] == s2[i])
        return 0;

    return (unsigned)s1[i] - (unsigned)s2[i];
}