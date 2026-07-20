#include <unistd.h>
void    ft_collapse_spaces(char *str)
{
    int i = 0;
    while((str[i] == ' '))
    {
        i++;
    }
    while(str[i])
    {
        if(!(str[i] == ' '))
        {
            write(1,&str[i],1);
        }
        if((str[i] == ' ') && (str[i+1] != ' ') && (str[i+1] != '\0'))
        {
            write(1," ",1);
        }
        i++;
    }
}

int main()
{
    char str[] = "   hello    world               ";
    ft_collapse_spaces(str);
    write(1,"\n",1);
}