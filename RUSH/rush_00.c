// rush(5,3) should display :
// $>./a.out
// o---o
// |   |
// o---o
// $>

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void rush(int b,int a)
{
    if (b <= 0 || a <= 0)
	return ;

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
               ft_putchar('o');
            }
            else if(j == 0 || j == b - 1)
            {
               ft_putchar('|');
            }
            else if( i == 0 || i == a - 1)
            {
                ft_putchar('-');;
            }
            else
            {
                ft_putchar(' ');
            }
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int main()
{
    rush(123, 42);
    return (0);
}