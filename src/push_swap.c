#include "../push_swap.h"

struct  s_node  *splitter(struct s_stack **A, struct s_stack **B)
{
    struct s_node *pivot_node;
    struct s_node *tmp;

    ft_printf("STRIP\n");
    tmp = (*A)->stack;
    while(tmp->next)
        tmp = tmp->next;
    pivot_node = tmp;
    tmp = (*A)->stack;
    while((*A)->stack->value != pivot_node->value)
    {
        if((*A)->stack->value < pivot_node->value)
            PB(A,B);
        else
            RA(A);
    }
    return pivot_node;
}

void    setter(struct s_stack **A,struct s_stack **B,int *num_arr,int *index)
{
    while((*A)->stack != (*A)->pivot)
    {
        if((*A)->stack->value == *index || (*A)->stack->next->value == *index)
            (*index) = checkA_Stack(A,num_arr,index);
        else if((*B)->stack->value == *index || (*B)->tail->value == *index)
            checkB_Stack(A,B,index);
        else
            PB(A,B);
    }
}

void    seeker(struct s_stack **A,struct s_stack **B,int *num_arr,int *index)
{
    print_set(A,B);
    if((*B)->stack != NULL)
        (*B)->tail = setB_Tail(B);
    while(checkA_Match(A,index) || checkB_Match(B,index))
    {
        ft_printf("SHI\n");
        print_set(A,B);
        ft_printf("index %i\n",(*index));
        print_set(A,B);
        ft_printf("iuab\n");
        if((*A)->stack->value == *index || ((*A)->stack->next && (*A)->stack->next->value == *index))
        {
            ft_printf("A_S\n");
            (*index) = checkA_Stack(A,num_arr,index);
        }
        else if(((*B)->stack != NULL)&&((*B)->stack->value == *index || (*B)->tail->value == *index))
        {
            ft_printf("DOPE\n");
            checkB_Stack(A,B,index);
        }
        ft_printf("iuabfioi\n");
        if((isSorted(A)) == 1 && (*B)->stack == NULL)
            return;
    }
    ft_printf("TAdddaaa index %i\n", *index);
}

void    stripper(struct s_stack **A,struct s_stack **B,int *num_arr)
{
    int i;
    
    i = checkNext(num_arr,A);
    ft_printf("%i\n",(*A)->pivot->value);
    ft_printf("%i\n",(*A)->tail->value);
    if((*A)->pivot->value != (*A)->tail->value)
    {
        ft_printf("hfbj\n");
        RA(A);
        (*A)->tail = (*A)->tail->next;
    }
    print_set(A,B);
    while((*A)->stack->value != (*A)->end)
    {
        ft_printf("%i\n", (*A)->end);
        PB(A,B);
    }
    (*B)->tail = setB_Tail(B);
    (*B)->pivot = (*B)->tail;
    print_set(A,B);
    while((isEmpty(B) == 0) || (*A)->stack->value != (*A)->end)
    {
        ft_printf("Yolo\n");
        if((*A)->stack->value != (*A)->end && (*B)->stack == NULL)
        {
            ft_printf("Hey dere\n");
            setter(A,B,num_arr,&i);
        }
        else
        {
            ft_printf("Hey sdfggh\n");
            seeker(A,B,num_arr,&i);
            print_set(A,B);
            ft_printf("tailly %i\n",(*B)->tail->value); 
        }
        if((*B)->stack != NULL && (*B)->stack == (*B)->pivot)
        {
            ft_printf("FUCK\n");
            PA(B,A);
            (*B)->pivot = (*B)->tail;
            continue;
        }
        if((*B)->stack == NULL)
            return ;
        if((*B)->stack->value > (*B)->pivot->value)
        {
            ft_printf("Pivvy %i\n",(*B)->pivot->value);
            PA(B,A);
        }
        else
        {
            (*B)->tail = (*B)->tail->prev;
            RRB(A,B);   
        }
        
    }
}

void    sorter(struct s_stack **A, struct s_stack **B,int *num_arr)
{
    int i;
    if((*B)->tail != NULL || (*B)->pivot != NULL)
    {
        (*B)->tail = setB_Tail(B);
        (*B)->pivot = (*B)->tail;
    }
    i = checkNext(num_arr,A);
    while((*B)->stack != NULL || (*A)->stack != (*A)->pivot || !isSorted(A))
    {
        ft_printf("HEllo\n");
        //ft_printf("TAIL %i\n", (*B)->tail->value);
        //ft_printf("PIVOT %i\n", (*B)->pivot->value);
        if((*A)->stack != (*A)->pivot && (*B)->stack == NULL)
            setter(A,B,num_arr,&i);
        else
        {
            ft_printf("Fuck\n");
            seeker(A,B,num_arr,&i);
            ft_printf("out\n");
            print_set(A,B);
        }
        if(isSorted(A) && (isEmpty(B) == 1) )
            return ;
        ft_printf("iuabfioiwfnwp\n");
        if((*B)->stack != NULL && (*B)->stack == (*B)->pivot)
        {
            ft_printf("Turnip\n");
            PA(B,A);
            (*B)->pivot = (*B)->tail;
            continue;
        }
        ft_printf("titties\n");
        if((*B)->stack != NULL && (*B)->stack->value > (*B)->pivot->value)
        {
            ft_printf("oh snap\n");
            PA(B,A);
        }
        else
        {
            print_set(A,B);
            if((*B)->stack == NULL)
                break ;
            else
            {
                (*B)->tail = (*B)->tail->prev;
                ft_printf("ughhhhhh\n");
                RB(A,B);
            }   
        }
        ft_printf("gfefefefefe\n");
    }
    print_set(A,B);
    ft_printf("%i     %i\n",(*A)->end, (*A)->end);
    if((*A)->stack->value != (*A)->end)
    {
        ft_printf("HEre we go\n");
        stripper(A,B,num_arr);
    }
}