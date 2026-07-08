#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
// 1. typedef
typedef int t_bool;
// 2. TRUE macro
# define TRUE 1
// 3. FALSE macro
# define FALSE 0
// 4. EVEN(n) macro
# define EVEN(n) ((n) % 2 == 0)
// 5. EVEN_MSG macro
# define EVEN_MSG "I have an even number of arguments.\n"
// 6. ODD_MSG macro
# define ODD_MSG "I have an odd number of arguments.\n"
// 7. SUCCESS macro
# define SUCCESS 0
#endif