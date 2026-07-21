#include <unistd.h>

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
    {
        i++;
    }
    return i;
}

void    ft_rotate_right(char *str)
{
    int i = 0;
    int last = ft_strlen(str) - 1;

    if(last != -1)
    {
        write(1,&str[last],1);

        while(i < last)
        {
            write(1,&str[i],1);
            i++;
        }
    }
}

int main()
{
    ft_rotate_right("");
    write(1,"\n",1);
}