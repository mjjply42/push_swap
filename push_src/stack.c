#include "../push_swap.h"

//Finds the next lowest value possible, in the given numbers to sort
int     checkNext(int *num_arr,struct s_stack **A)
{
    int number;

    number = (*A)->max_a;
    while(number > 0)
    {
        if(num_arr[number] == 1)
        {
            number *=(-1);
            break ;
        }
        number--;
    }
    if(number == 0)
    {
        while(num_arr[number] != 2)
            number++;
    }
    return number;
}

//Checks top of stack A for immediate match to the value
int     checkA_Stack(struct s_stack **A,int *num_arr,int *index)
{
    if((*A)->stack->value == *index)
    {
        RA(A);
            if(*index < 0)
                num_arr[(*index)*-1]++;
            else
                num_arr[*index]-=2;
            if(*index < (*A)->max_a)
                (*index) = checkNext(num_arr,A);
    }
    else
        SA(A);
    return *index;
}

//Checks top and bottom of stack B for immediate match to the value
void    checkB_Stack(struct s_stack **A, struct s_stack **B,int *index)
{
    if((*B)->stack->value == *index)
        PA(B,A);
    else
    {
        if((*B)->pivot == (*B)->tail)
        {
            (*B)->pivot = (*B)->pivot->prev;
            (*B)->tail = (*B)->tail->prev;
        }
        else
            (*B)->tail = (*B)->tail->prev;
        RRB(A,B);
    }
}

//Checks stack A for match to the value
int     checkA_Match(struct s_stack **A,int *index)
{
    int is_a;
    int a_next;
    int a_top;

    is_a = 1;
    a_next = 1;
    a_top = 1;
    if((*A)->stack->value != *index)
        a_top = 0;
    if((*A)->stack->next == NULL)
        a_next = 0;
    else
    {
        if((*A)->stack->next->value != *index)
            a_next = 0;
    }
    if(a_top == 0 && a_next == 0)
        is_a = 0;
    return is_a;
}

//Checks stack B for match to the value
int     checkB_Match(struct s_stack **B,int *index)
{
    int is_b;
    int b_tail;
    int b_top;

    is_b = 1;
    b_tail = 1;
    b_top = 1;
    if((*B)->stack == NULL)
        is_b = 0;
    else
    {
        if((*B)->stack->value != *index)
            b_top = 0;
        if((*B)->tail == NULL)
            b_tail = 0;
        else
            if((*B)->tail->value != *index)
                b_tail = 0;
    }
    if(b_top == 0 && b_tail == 0)
        is_b = 0;
    return is_b;
}