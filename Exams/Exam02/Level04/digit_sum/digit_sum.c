#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>

void	putnbr(int n)
{
	char	c;

	if (n >= 10)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int main(int ac,char *av[])
{
    if(ac != 2)
    {
        write(1,"\n",1);
        return 0;
    }
    int i = 0;
    
    int find;
    int nb;
    while(av[1][i])
    {
        nb = 0;
        find = 0;
        while(av[1][i] && av[1][i] >= '0' && av[1][i] <= '9')
        {
            nb = nb + (av[1][i] - '0');
            find = 1;
            i++;
        }
        if(find)
        {
            putnbr(nb);            
            if(av[1][i] == '\0')
                break;
        }
            write(1,&av[1][i],1);
        
        i++;
    }
    write(1,"\n",1);
    return 0;
}