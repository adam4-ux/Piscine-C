#include <unistd.h>
#include <stdio.h>

int main(int ac,char *av[])
{
    if(ac <= 2)
    {
        write(1,"\n",1);
        return 0;
    }
    int i = 0;
    int j;
    int k;

    int repet = 0;
    int found;
    while(av[1][i])
    {
        repet = 0;
        j = 0;
        while(j < i)
        {
            if(av[1][i] == av[1][j])
            {
                repet = 1;
            }
            j++;
        }

        if(!repet)
        {
            found = 1;
            j = 2;
            while(j < ac)
            {
                k = 0;
                while(av[j][k] && av[j][k] != av[1][i])
                {
                    k++;
                }
                if(av[j][k] == '\0')
                {
                    found = 0;
                }
            j++;
            }
        }

        if(found)
        {
            write(1,&av[1][i],1);
        }
        i++;
    }
    write(1,"\n",1);
    return 0;
}