#include <unistd.h>
void    ft_putchar(char c)
{
        write(1,&c,1);
}

void    ft_print_combn(int n)
{
        int arr[10];
        int i = 0;
        int j;
        if(n <= 0 || n >=10)
        {
                return;
        }

        while(i < n)
        {
                arr[i] = i;
                i++;
        }

        while(1)
        {
                i = 0;
                while(i < n)
                {
                        ft_putchar(arr[i] + '0');
                        i++;
                }

                if(arr[0] == 10 - n)
                {
                        break;
                }
                write(1,", ",2);

                i = n - 1;
                while(i >= 0)
                {
                        if(arr[i] < 9 - (n - 1 - i))
                        {
                                arr[i]++;
                                j = i + 1;
                                while(j < n)
                                {
                                        arr[j] = arr[j-1] + 1;
                                                j++;
                                }
                                break;
                        }
                i--;
                }
        }
}