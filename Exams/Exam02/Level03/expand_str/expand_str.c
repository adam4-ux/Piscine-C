#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int ac,char *av[])
{
    if(ac != 2)
    {
        write(1,"\n",1);
        return 0;
    }
    int i = 0;
    int start;
    int find;
    int nb;
    while(av[1][i])
    {
        nb = 0;
        find = 0;
        while(av[1][i] && av[1][i] >= '0' && av[1][i] <= '9')
        {
            nb = nb * 10 + (av[1][i] - '0');
            find = 1;
            i++;
        }
        if(find)
        {
            if(av[1][i] == '\0')
                break;
                
            start = 0;
            while(start < nb)
            {
                write(1,&av[1][i],1);
                start++;
            }
        }
        else
            write(1,&av[1][i],1);
        
        
        i++;
    }
    write(1,"\n",1);
    return 0;
}