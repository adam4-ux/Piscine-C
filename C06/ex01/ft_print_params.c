#include <unistd.h>
int main(int argc,char *argv[])
{
    int i = 1;
    int j = 0;

    while(i <  argc)
    {
        j = 0;
        while(argv[i][j])
        {
            write(1,&argv[i][j],1);
            j++;
        }
            write(1,"\n",1);
        i++;
    }
}