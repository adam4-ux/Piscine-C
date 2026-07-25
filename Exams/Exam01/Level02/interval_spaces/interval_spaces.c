#include <unistd.h>
int ft_strlen(char *c)
{
    int i = 0;
    while(c[i])
    {
        i++;
    }
    return i;
}
int main(int ac,char *av[])
{
    if(ac != 2)
    {
        write(1,"\n",1);
        return 0;
    }
    int len = ft_strlen(av[1]) - 1;
    int i = 0;
    while(av[1][i])
    {
        write(1,&av[1][i],1);
        if(i < len)
        {
            write(1,"   ",3);
        }
        i++;
    }
    write(1,"\n",1);
}