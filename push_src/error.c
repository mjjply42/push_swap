#include "../push_swap.h"
#include "../checker.h"

//Error checking the input for words: "1 2 3 four"
int     check_noLet_error(int ac,char **av)
{
    int i = 1;
    int j = 0;
    if(ac < 1)
        return 1;
    while(av[i] != '\0')
    {
        j = 0;
        while(av[i][j] != '\0')
        {
            if(ft_isalpha(av[i][j]))
                terminate_program();
            j++;
        }
        check_int(av[i]);
        i++;
    }
    return 1;
}

//Error checking the input for numbers larger than INT_MAX
int     check_int(char *str)
{
    unsigned long long test;
    test = ft_atoi(str);
    if(test > 2147483647 || (long)test < -2147483648)
        terminate_program();
    return 1;
}

//Error checking the input for duplicate integers: "1 2 3 2"
int     check_doubles(int *num_arr,int length)
{
    int i;
    int j;
    int tmp;
    int index;

    index = 0;
    i = 0;
    j = 0;
    tmp = 0;
    while(i < length)
    {
        tmp = num_arr[i];
        index = i;
        j = 0;
        while(j < length)
        {
            if(tmp == num_arr[j] && index != j)
            {
                ft_printf("Wha\n");
                terminate_program();
            }
            j++;
        }
        i++;
    }
    return 1;
}

//Error checking the input for proper formatting. Has to be command, then newline. No other characters
// can interrupt the command + newline order.
void        check_formatting(char prev_char,char curr_char,char next_char)
{

    char characters[5] = {'r','a','b','p','s'};
    char space;
    int i;
    int match;

    i = -1;
    space = '\n';
    match = 0;
    while(characters[++i])
        if(curr_char == characters[i] || curr_char == space || curr_char == '\0')
            match = 1;
    i = -1;
    if(curr_char == space)
    {
        while(characters[++i])
        {
            if(prev_char == characters[i])
                match = 1;
            if(next_char == characters[i] || next_char == '\0')
                match = 1;
        }        
    }
    if(match == 0)
        terminate_program();
}