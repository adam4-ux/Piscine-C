#include <unistd.h>
void convert_hex(char s)
{
    char hex[] = "0123456789abcdef";
    
    write(1,&hex[s / 16],1);
    write(1,&hex[s % 16],1);
}
void ft_putstr_non_printable(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 32 && str[i] < 127)
            write(1,&str[i],1);

        else
        {
            write(1, "\\", 1);
            convert_hex(str[i]);
        }
        i++;
    }
}