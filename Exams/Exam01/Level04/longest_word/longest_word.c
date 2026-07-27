#include <unistd.h>
#include <stdio.h>
int is_separator(char c)
{

    if(c == ' ' || c == '\t')
    {
        return 1;
    }
    return 0;
}

int main(int ac,char *av[])
{
    if(ac != 2)
    {
        write(1,"\n",1);
        return 0;
    }

    int word_start = 0;
    int word_end;
    int longest_start = 0;
    int longest_end = 0;
    int longest_length = 0;
    int word_length;

    while (av[1][word_start])
    {
        while(av[1][word_start] && is_separator(av[1][word_start]))
            word_start++;

        word_end = word_start;
        while(av[1][word_end]&& !is_separator(av[1][word_end]))
        word_end++;

        word_length = word_end - word_start;

        if(word_length > longest_length)
        {
            longest_start = word_start;
            longest_end = word_end;
            longest_length = word_length;
        }
        
        word_start = word_end;     
    }

    while(longest_start < longest_end)
    {
        write(1,&av[1][longest_start++],1);
    }
    write(1,"\n",1);
}