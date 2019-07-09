#include "../push_swap.h"

int     checkMax(int content, int *big)
{
    if(content > *big)
        *big = content;       
    return *big;
}