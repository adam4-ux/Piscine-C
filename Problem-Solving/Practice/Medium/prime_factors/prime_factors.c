// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	if(argc != 2)
// 	{
// 		printf("wrong number of arguments\n");
// 		return 0;
// 	}
// 	int nb = atoi(argv[1]);

// 	if(nb == 1)
// 	{
// 		printf("1\n");
// 		return 0;
// 	}

// 	int division = 2;
// 	int first = 1;
	
//     while (nb > 1)
//     {
//         if (nb % division == 0)
//         {
//             if (!first)
//                 printf("*");
//             printf("%d", division);
//             nb /= division;
//             first = 0;
//         }
//         else
//             division++;
//     }
// 	printf("\n");
// }
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

int words_count(char *s)
{
    int in_word;
    int count;

    in_word = 0;
    count = 0;
    while(*s)
    {
        if ((*s != ' ' && *s != '\t'))
        {
            if (!in_word)
            {
                count++;
                in_word = 1;
            }
        }
        else
            in_word = 0;
        s++;
    }
    return (count);
}

int    main(int ac, char **av)
{
    if (ac != 2)
    {
        write( 1, "wrong number of arguments\n", 26);
            return (0);
    }
    int len;
    int start;
    int end;
    int words;
    

    len = ft_strlen(av[1]) - 1;
    end = 0;
    words = words_count(av[1]);

    while(words >= 1)
    {
        while(len >= 0 && (av[1][len] != ' ' && av[1][len] != '\t'))
        {
            len--;
            end++;
        }
        start = len + 1;
        while(end > 0 )
        {
            write(1, &av[1][start], 1);
            start++;
            end--;
        }
        len--;
        if (words != 1)
            write(1, " ", 1);
        words--;
    }
    write(1, "\n", 1);
    return (0);
}