#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}


int shift(char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        c = c + 32;
    }
    
    if(c >= 'a' && c <= 'z')
    {
        int res = c - 'a';
        return res;
    }
    return 0;
}

int main(int ac,char *av[])
{
    if(ac != 3)
    {
        write(1,"\n",1);
        return 0;
    }

    int len = ft_strlen(av[2]);
    char c;
    int i = 0;
    int j = 0;
    while(av[1][i])
    {
        if((av[1][i] >= 'a' && av[1][i] <= 'z' ) || (av[1][i] >= 'A' && av[1][i] <= 'Z'))
        {
            int total = (shift(av[1][i]) + shift(av[2][j])) % 26;

            if(av[1][i] >= 'a' && av[1][i] <= 'z' )
            {
                c = 'a' + total;
            }
            else
            {
                c = 'A' + total;          
            }

            write(1,&c,1);

            j++;

        if(j == len)
            j = 0;
        }
        else
        {
            write(1, &av[1][i], 1);
        }
        i++;
    }
    write(1,"\n",1);
}
