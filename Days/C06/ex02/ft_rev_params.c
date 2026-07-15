#include <unistd.h>
int main(int argc,char *argv[])
{
    int ac = argc - 1;

    int i;
    while(ac >= 1)
    {
        i = 0;
        while(argv[ac][i])
        {
            write(1,&argv[ac][i],1);
            i++;
        }
        write(1,"\n",1);
        ac--;
    }
}