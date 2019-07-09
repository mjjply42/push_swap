#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "libft/printf/ft_printf.h"

/////////////////////////////////////////////
/////*Structs for Stack and Stack Nodes*/////
/////////////////////////////////////////////

struct      s_node
{
    int     value;
    struct  s_node *next;
    struct  s_node *prev;
};

struct      s_stack
{
    int     capacity;
    int     max_a;
    int     max_b;
    struct  s_node *stack;
};

struct      s_node *pop(struct s_stack **st);
struct      s_stack *initStack();
struct      s_node *initNode(int value);
struct      s_node  *initList(struct s_node *node, struct s_node *head);
void        push(struct s_stack **st, struct s_node *node);
void        toStack(int value, struct s_stack **A);
void        set_datum(struct s_stack **A, int *num_arr, int size);
void        SA(struct s_stack **A);
void        SB(struct s_stack **B);
void        SS(struct s_stack **A, struct s_stack **B);
void        PB(struct s_stack **A, struct s_stack **B);
void        PA(struct s_stack **B, struct s_stack **A);
void        RA(struct s_stack **A);
void        RB(struct s_stack **B);
void        RR(struct s_stack **A, struct s_stack **B);
void        RRA(struct s_stack **A);
void        RRB(struct s_stack **B);
void        RRR(struct s_stack **A, struct s_stack **B);
void        swap(int *a, int *b);
void        print_stack(struct s_stack **Stack);
void        print_set(struct s_stack **A, struct s_stack **B);
int         *initArray(char **list, int length);
int         *initArray(char **list, int length);
int         checkMax(int content, int *big);

#endif