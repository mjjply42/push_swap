#include "../push_swap.h"

void    push(struct s_stack **st, struct s_node *node)
{
    node->next = (*st)->stack;
    if((*st)->stack == NULL)
        (*st)->stack = node;
    else
    {
        (*st)->stack->prev = node;
        (*st)->stack = node;
    }
    
}

struct  s_node *pop(struct s_stack **st)
{
    struct s_node *tmp;

    tmp = (*st)->stack;
    (*st)->stack = tmp->next;
    tmp->next = NULL;
    return tmp;
}

int     isEmpty(struct s_stack **stack)
{
    int ret;

    ret = 0;
    if((*stack)->stack == NULL)
        ret = 1;
    else
        ret = 0;
    return ret;
}

struct s_node   *find_node(struct s_stack **st,int val)
{
    struct s_node *tmp;

    tmp = (*st)->stack;
    while(tmp && tmp->value != val)
        tmp = tmp->next;
    return tmp;
}

//Simple Quicksort function
void quicksort(int *number,int first,int last)
{
    int i;
    int j;
    int pivot;
    int temp;
    
    if(first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while(i < j)
        {
            while(number[i] <= number[pivot] && i<last)
                i++;
            while(number[j] > number[pivot])
                j--;
            if(i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}