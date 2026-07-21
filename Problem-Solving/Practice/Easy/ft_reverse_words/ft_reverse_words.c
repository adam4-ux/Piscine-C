#include <unistd.h>
int is_space(char c)
{
    if(c == ' ')
    {
        return 1;
    }
    return 0;
}
void    ft_reverse_words(char *str)
{
    int first = 0;
    int last;
    while(str[first])
    {
        while(str[first] && is_space(str[first]))
        {
            write(1,&str[first],1);
            first++;
        }
        last = first;
        while(str[last] && !is_space(str[last]))
        {
            last++;
        }
        int end = last - 1;

        while(end >= first)
        {
            write(1,&str[end],1);
            end--;
        }
        first = last;
    }
}
int main()
{
    char str[] = "he adam llo 1337 world";
    ft_reverse_words(str);
    write(1,"\n",1);
}