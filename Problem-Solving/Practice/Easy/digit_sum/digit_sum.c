    #include <unistd.h>
    #include <stdio.h>

    long atoi(char *str)
    {
        long i = 0;
        long result = 0;
        while(str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        return result;
    }

    int main(int ac,char *av[])
    {
        if(ac != 2)
        {
            write(1,"\n",1);
            return 0;
        }

        int nb = atoi(av[1]);
    }