// rush(5,3) should display :
// $>./a.out
// o---o
// |   |
// o---o
// $>

#include <unistd.h>

void rush(int b,int a)
{
    int i = 0;
    int j;

    while(i < a)
    {
        j = 0;
        while(j < b)
        {
            if(i == 0 && j == 0 ||
            i == 0 && j == b -1 ||
            i == a-1 && j == 0 ||
            i == a - 1 && j == b -1)
            {
                write(1,"o",1);
            }
            else if(j == 0 || j == b - 1)
            {
                write(1,"|",1);
            }
            else if( i == 0 || i == a - 1)
            {
                write(1,"-",1);
            }
            else
            {
                write(1," ",1);
            }
            j++;
        }
        write(1,"\n",1);
        i++;
    }
}

int main()
{
    rush(123, 42);
    return (0);
}