#include <unistd.h>
void    hermione(char *str)
{
     int i = 0;
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }

    if(str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] = str[0] - 32;
        i++;
    }
    i = 1;
    while(str[i])
    {
        if(!(str[i] >= 'a' && str[i] <= 'z'))
        {
            if(str[i+1] >= 'a' && str[i+1] <= 'z')
            {
                str[i+1] = str[i+1] - 32;
                i++;
            }
        }
        i++;
    }

    i = 0;
    while(str[i])
    {
        write(1,&str[i],1);
        i++;
    }
}