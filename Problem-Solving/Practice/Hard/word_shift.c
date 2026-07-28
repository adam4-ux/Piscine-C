#include <unistd.h>
#include <stdlib.h>

int is_separator(char c)
{
    if(c == ' ' || c == '\t')
    {
        return 1;
    }
    return 0;
}

int count_words(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        while(str[i] && is_separator(str[i]))
            i++;

        if(str[i])
            count++;

        while(str[i] && !is_separator(str[i]))
            i++;     
    }
    return count;
}

char **ft_split(char *str)
{
    int i = 0;
    int j;
    int word = count_words(str);

    char **arr = malloc((word + 1) * sizeof(char*));
    if(!arr)
        return NULL;

    int start = 0;
    int end;

    while(i < word)
    {
        while(str[start] && is_separator(str[start]))
            start++;

        end = start;

        while(str[end] && !is_separator(str[end]))
           end++; 

        arr[i] = malloc((end - start + 1) * sizeof(char));
        
        if(!arr[i])
        {
            while(i > 0)
            {
                free(arr[--i]);
            }
            free(arr);
            return NULL;
        }

        j = 0;
        while(start < end)
            arr[i][j++] = str[start++];

        arr[i][j] = '\0';
        i++;
    }
        arr[word] = NULL;

    return arr;
}

int	main(int argc, char **argv)
{
	if(argc != 2)
	{
		write(1,"wrong number of arguments\n",26);
		return 0;
	}
	int words = count_words(argv[1]);

    char **arr = ft_split(argv[1]);
    
    if (!arr)
    {
        write(1, "\n", 1);
        return (0);
    }

	int j;
	int k = 1;
	while(k < words)
	{
		j = 0;
		while(arr[k][j])
		{
			write(1,&arr[k][j],1);
			j++;
		}
			write(1," ",1);
		k++;
	}

	j = 0;
	while(arr[0][j])
	{
		write(1,&arr[0][j],1);
		j++;
	}
	write(1,"\n",1);

	int words_count = count_words(argv[1]);
	for (int i = 0; i < words_count; i++)
		free(arr[i]);
	free(arr);

	return (0);
}
