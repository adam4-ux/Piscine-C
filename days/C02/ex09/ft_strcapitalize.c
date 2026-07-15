    char *ft_strcapitalize(char *str)
    {
        int i =0;
        while(str[i])
        {
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] = str[i] + 32;
            }
            i++;
        }
        if(str[0] >= 'a' && str[0] <= 'z')
            str[0] = str[0] - 32;

        i = 1;
        while(str[i] == ' ')
            i++;

        while(str[i])
        {
            if(str[i-1] == ' ' || str[i-1] == '-' || str[i-1] == '+')
            {
                if(str[i] >= 'a' && str[i] <= 'z')
                {
                    str[i] = str[i] - 32;
                }
            }
            i++;
        }
        return str;
    }