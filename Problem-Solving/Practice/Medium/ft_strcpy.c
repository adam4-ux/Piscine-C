// #include <stdio.h>

// int	ft_strcmp(char *****dest,char ********src)
// {
//     while(*****dest && *****dest == ********src)
//     {
//         (****dest)++;
//         (*******src)++;
//     }
//     return (********src - *****dest);
// }
// int main()
// {
//     char *s = "ab";
//     char **ss = &s;
//     char ***sss = &ss;
//     char ****ssss = &sss;
//     char *****sssss = &ssss;
//     char ******ssssss = &sssss;
//     char *******sssssss = &ssssss;

//     char *a = "aa";
//     char **aa = &a;
//     char ***aaa = &aa;
//     char ****aaaa = &aaa;

//     int res = ft_strcmp(&aaaa,&sssssss);

//     printf("%d\n",res);
// }


// void swap(int *****a ,int **b)
// {
//     int tmp;

//     tmp = **b;
//     **b = *****a;
//     *****a = tmp;
// }
// int main()
// {
//     int p = 5;
//     int *a = &p;
//     int **aa = &a;
//     int ***aaa = &aa;
//     int ****aaaa = &aaa;

//     int k = 9;
//     int *b = &k;

//     swap(&aaaa,&b);

//     printf("a = %d ,b = %d\n",p,k);
// }
// #include <unistd.h>
// void ft_print(char *s)
// {
//     if(*s == '\0')
//         return;

//     write(1,s,1);
//     ft_print(s+1);
// }

// int main()
// {
//     ft_print("adam");
//     write(1,"\n",1);
// }