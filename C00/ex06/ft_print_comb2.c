#include <unistd.h>
void ft_print_comb2(void)
{
    int i = 0;
    int j;

    while(i <= 98)
    {
        j = i + 1;
        while (j <= 99)
        {
            char x1 = i / 10 + '0'; 
            char x2 = i % 10 + '0';  
            char x3 = j / 10 + '0';  
            char x4 = j % 10 + '0'; 
            
            write(1,&x1,1);
            write(1,&x2,1);
            write(1," ",1);
            write(1,&x3,1);
            write(1,&x4,1);

            if(i != 98)
                write(1,", ",2);
            j++;
        }
        i++;
    }
}
