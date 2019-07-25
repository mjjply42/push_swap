#include "../push_swap.h"
#include "../checker.h"

//Sets the tail node of the stack B
struct s_node   *setB_Tail(struct s_stack **B)
{
    struct s_node *tmp;

    tmp = (*B)->stack;
    while(tmp->next)
        tmp = tmp->next;
    return tmp;
}

//Creats node with new value (initNode()), then adds node to stack A
void toStack(int value, struct s_stack **A)
{
    struct s_node *node;

    node = NULL;
    node = initNode(value);
    if((*A)->stack == NULL)
    {
        (*A)->stack = node;
        node->next = NULL;
    }
    else
    {
        (*A)->stack->prev = node;
        node->next = (*A)->stack;
        (*A)->stack = node;
    }
    (*A)->capacity++;
}

//Finds optimal side to pull from, to get to the Max value
int    findSide(struct s_stack **A,int value)
{
    int side;
    struct s_node *tmp;

    tmp = (*A)->stack;
    side = 0;
    while(tmp->value != value)
    {
        side++;
        tmp = tmp->next;
    }
    while(tmp)
    {
        side--;
        tmp = tmp->next;
    }
    side = (side >= 0 ? 1:0);
    return side;
}

//Sets stack A data from number array, gathered from console input
void    set_datum(struct s_stack **A, int *num_arr, int size)
{
    struct s_node *node;
    int i;
    int big;

    i = 0;
    node = NULL;
    big = 0;
    while(i < size)
    {
        (*A)->max_a = checkMax(num_arr[i], &big);
        i++;
    }
    i--;
    while(i >= 0)
    {
        toStack(num_arr[i], A);
        i--;
    }
}

//Finds the next up value in the array, to pair with the next upcoming value
int     getNextValue(struct s_stack **A,int big)
{
    struct s_node *tmp;
    int i;
    int next;

    i = 0;
    tmp = (*A)->stack;
    next = tmp->value;
    while(tmp->next)
    {
        if(next < tmp->next->value && tmp->next->value != big)
            next = tmp->next->value;
        tmp = tmp->next;
    }
    return next;
}

int         findBig(struct s_stack **B)
{
    int big;
    struct s_node *tmp;

    tmp = (*B)->stack;
    big = 0;
    if((*B)->stack != NULL)
    {
        big = (*B)->stack->value;
        if(tmp->next == NULL)
            return big;
        while(tmp)
        {
            if(tmp->value > big)
                big = tmp->value;
            tmp = tmp->next;
        }
    }
    return big;
}

int     *make_arr(struct s_stack **B,int incoming)
{
    int i;
    int *arr;
    struct s_node *tmp;

    tmp = (*B)->stack;
    i = 0;
    arr = malloc(sizeof(int) * (*B)->capacity + 1);
    arr[i] = incoming;
    i++;
    while(i < (*B)->capacity + 1)
    {
        arr[i] = tmp->value;
        tmp = tmp->next;
        i++;
    }
    quicksort(arr,0,(*B)->capacity);
    return arr;
}

struct  s_node  *findSpot(struct s_stack **B,int incoming)
{
    struct s_node *tmp;
    int *arr;
    int i;

    i = 0;
    tmp = (*B)->stack;
    arr = make_arr(B, incoming);
    if(tmp->next == NULL)
        return tmp;
    while(i < (*B)->capacity + 1)
    {
        if(incoming == arr[0])
            return find_node(B,arr[i + 1]);
        if(arr[i] == incoming)
        {
            if(i == (*B)->capacity)
                return find_node(B,arr[i-1]);
            tmp = find_node(B,arr[i + 1]);
            return tmp;
        }
        i++;
    }
    free(arr);
    return tmp;
}

void        to_spot3(struct s_stack **A,struct s_stack **B,struct s_node **tmp,int tag)
{
    if(tag == 1)
    {
        RB(A,B);
        toEnd(tmp);
    }
    else if(tag == 0)
    {
        RRB(A,B);
        toEnd(tmp);
    }
}

void        to_spot2(struct s_stack **A,struct s_stack **B, struct s_node **tmp,struct s_node *spot)
{
    while(spot != (*tmp))
    {
        RRB(A,B);
        toEnd(tmp);
    }
}

void        to_spot(struct s_stack **A,struct s_stack **B, struct s_node **tmp,struct s_node *spot)
{
    while(spot != (*tmp))
    {
        (*tmp) = (*tmp)->prev;
        RRB(A,B);
    }
}

void        set_pos(struct s_stack **A,struct s_stack **B,struct s_node *spot,int incoming)
{   
    struct s_node *tmp;

    tmp = (*B)->stack;
    toEnd(&tmp);
    if(incoming < (*B)->stack->value && incoming < tmp->value)
    {
        to_spot2(A,B,&tmp,spot);
        if(incoming > spot->value)
            RRB(A,B);
    }
    else if(incoming < (*B)->stack->value && incoming > tmp->value)
        to_spot(A,B,&tmp,spot);
    else if(incoming > (*B)->stack->value && incoming > tmp->value)
    {
        to_spot(A,B,&tmp,spot);
        if(incoming > spot->value)
            RB(A,B);
        else
            return;
    }
    else if(incoming > (*B)->stack->value && incoming < tmp->value)
        to_spot(A,B,&tmp,spot);
}

void        side1(struct s_stack **A,struct s_stack **B,struct s_node *spot,int incoming)
{
    if((*B)->stack->next != NULL)
       set_pos(A,B,spot,incoming);
    else
        return ;
}

void        analyze(struct s_stack **A,struct s_stack **B,struct s_node *tmp,int incoming,struct s_node *spot)
{
    while((*B)->stack->value < incoming && (*B)->stack->next->value > (*B)->stack->value)
        to_spot3(A,B,&tmp,1);
    while((*B)->stack->value != spot->value)
        to_spot3(A,B,&tmp,1);
    return ;
}

void        side0(struct s_stack **A,struct s_stack **B,struct s_node *spot,int incoming)
{
    struct s_node *tmp;

    tmp = (*B)->stack;
    toEnd(&tmp);
    if((*B)->stack->next != NULL)
    {
        if(incoming < (*B)->stack->value && incoming < tmp->value)
        {
            while(spot->value != (*B)->stack->value)
                to_spot3(A,B,&tmp,1);
        }
        else if(incoming < (*B)->stack->value && incoming > tmp->value)
        {
            while(incoming > tmp->value)
                to_spot3(A,B,&tmp,0);
        }
        else if(incoming > (*B)->stack->value && incoming > tmp->value)
            analyze(A,B,tmp,incoming,spot);
        else if(incoming > (*B)->stack->value && incoming < tmp->value)
            return ;
    }
    else
        return ;
}

//This preps, or moves items around in Stack B so that the next incoming item will be in place in relation
//to the top element, either by SB or RB.
void        prepB(struct s_stack **A,struct s_stack **B,int incoming)
{
    int side;
    struct s_node *spot;

    spot = (*B)->stack;
    side = 0;
    (*B)->max_a = findBig(B);
    if((*B)->stack != NULL)
    {
        spot = findSpot(B, incoming);
        side = findSide(B,spot->value);
        if(side == 1)
            side1(A,B,spot,incoming);
        else
            side0(A,B,spot,incoming);
    }
}

//Moves pointer given as argument, to the end of the stack.
void        toEnd(struct s_node **tmp)
{
    while((*tmp)->next)
        *tmp = (*tmp)->next;
}

//Sets status of elements that are currently sorted, in respects to the Max of the stack.
int        set_sort_status(struct s_stack **A)
{
    int num;
    struct s_node *tmp;

    num = 0;
    tmp = (*A)->stack;
    while(tmp->value != ((*A)->max_a))
        tmp = tmp->next;
    tmp->sorted = 1;
    while(tmp->prev->value == getNextValue(A,tmp->value))
    {
        tmp = tmp->prev;
        tmp->sorted = 1;
    }
    return num;
}

//Orders bottom stack B values
void        part_combine(struct s_stack **A,struct s_stack **B)
{
    struct s_node *tmp;

    tmp = (*B)->stack;
    toEnd(&tmp);
    while(tmp->value > (*B)->stack->value)
    {
        tmp = tmp->prev;
        RRB(A,B);
    }
}

//Gets us either, the very second highest item to the top of the stack, or the most sorted stack value
void        align_to_front(struct s_stack **A,struct s_stack **B)
{
    struct s_node *tmp;
    tmp = (*A)->stack;
    while((*A)->stack->sorted != 1 || (*A)->stack->value != (*A)->max_a ||
            (*A)->stack->value != getNextValue(A,(*A)->max_a))
    {
        if((*B)->capacity == 2)
            if((*B)->stack->value < (*B)->stack->next->value)
                SB(A,B);
        prepB(A,B,(*A)->stack->value);
        PB(A,B);
    }
    while((*A)->stack->value == getNextValue(A,(*A)->max_a) && ((*A)->stack->next != NULL && (*A)->stack->next->value != (*A)->max_a))
    {
        if((*B)->capacity == 2)
            if((*B)->stack->value < (*B)->stack->next->value)
                SB(A,B);
        SA(A);
        prepB(A,B,(*A)->stack->value);
        PB(A,B);
    }
    part_combine(A,B);
}