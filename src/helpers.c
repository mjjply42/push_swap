#include "../push_swap.h"

int     checkMax(int content, int *big)
{
    if(content > *big)
        *big = content;       
    return *big;
}

void    swap(int *a, int *b)
{
    int tmp;

    tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}