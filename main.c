#include "push_swap.h"

int main(int ac, char **av)
{
    int length;
    int *num_list;
    struct s_stack *stackA;
    struct s_stack *stackB;

    length = ac-1;
    stackA = initStack();
    stackB = initStack();
    num_list = initList(av, length);
    
    return 1;
}