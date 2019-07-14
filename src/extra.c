#include "../push_swap.h"

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
    ft_printf("NUMBER %i\n", number);
    if(number == 0)
    {
        while(num_arr[number] != 2)
            number++;
    }
    return number;
}

int     checkA_Stack(struct s_stack **A,int *num_arr,int *index)
{
    if((*A)->stack->value == *index)
    {
        ft_printf("TellME\n");
        RA(A);
            if(*index < 0)
                num_arr[(*index)*-1]++;
            else
                num_arr[*index]-=2;
            if(*index < (*A)->max_a)
                (*index) = checkNext(num_arr,A);
            print_stack(A);
    }
    else
        SA(A);
    ft_printf("Test\n");
    print_stack(A);
    return *index;
}

void    checkB_Stack(struct s_stack **A, struct s_stack **B,int *index)
{
    if((*B)->stack->value == *index)
    {
        ft_printf("CHECK\n");
        PA(B,A);
    }
    else
    {
        ft_printf("CHECKli\n");
        if((*B)->pivot == (*B)->tail)
        {
            (*B)->pivot = (*B)->pivot->prev;
            (*B)->tail = (*B)->tail->prev;
        }
        else
            (*B)->tail = (*B)->tail->prev;
        ft_printf("TAIL HERE %i\n",(*B)->tail->value);
        RRB(A,B);
    }
}

struct s_node   *setB_Tail(struct s_stack **B)
{
    struct s_node *tmp;

    tmp = (*B)->stack;
    while(tmp->next)
        tmp = tmp->next;
    return tmp;
}

int     checkMatch(struct s_stack **A,struct s_stack **B,int *index)
{
    if((*A)->stack->value != *index)
    {
        if((*A)->stack->next && (*A)->stack->next->value != *index)
        {
            if((*B)->stack == NULL)
            {
                ft_printf("WTF\n");
                return 0;
            }
            else
            {
                if((*B)->stack->value != *index || (*B)->tail->value != *index)
                {
                    ft_printf("%i  %i\n", (*B)->stack->value, (*B)->tail->value);
                    return 0;
                }
            }
        }
        return 0;
    }
    return 1;
}

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