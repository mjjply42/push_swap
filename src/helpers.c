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

void    add_command(struct s_stack **A,char *command)
{
    if(command == NULL)
        return ;
    initList(&(*A)->list, command);
}

int     isSorted(struct s_stack **A)
{
    struct s_node *tmp;

    tmp = (*A)->stack->next;
    while(tmp)
    {
        if(tmp->value > tmp->prev->value)
            tmp = tmp->next;
        else
            return 0;
    }
    return 1;
}

void    set_count_array(struct s_stack **A,int *num_arr)
{
    struct s_node *tmp;
    int i;

    i = 0;
    tmp = NULL;
    while(i <= (*A)->max_a)
    {
        num_arr[i] = 0;
        i++;
    }
    tmp = (*A)->stack;
    while(tmp)
    {
        if(tmp->value >= 0)
            num_arr[tmp->value]+= 2;
        else
            num_arr[(tmp->value)*-1]--;
        tmp = tmp->next;
    }
}