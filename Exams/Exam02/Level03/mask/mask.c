#include <unistd.h>
int spe(char c)
{
    if(c == ' ' || c == '\t' )
    {
        return 1;
    }
    return 0;
}

int main(int ac,char *av[])
{
    if(ac != 2)
    {
        write(1,"\n",1);
        return 0;
    }
    int i = 0;
    while(av[1][i] == ' ' || av[1][i] == '\t')
    {
        write(1, &av[1][i], 1);
        i++;
    }

    int first = 0;

    if (av[1][i] == '\0')
    {
        write(1, "\n", 1);
        return 0;
    } 
    if(av[1][i+1] == '\0')
    {
        write(1,&av[1][i],1);
        write(1,"\n",1);
        return 0;
    }

    while(av[1][i])
    {
        while(!spe(av[1][i]))
        {
            if(first == 0)
            {
                write(1,&av[1][i],1);
                first = 1;
            }
            else if(av[1][i+1] == '\0')
            {
                write(1,&av[1][i],1);
                write(1,"\n",1);
                return 0;
            }
            else if(spe(av[1][i+1]))
            {
                write(1,&av[1][i],1);
            }
            else
            {
                write(1,"*",1);
            }
            i++;
        }
        while(spe(av[1][i]))
        {
            write(1,&av[1][i],1);
            i++;
        }
        first = 0;
    }
}