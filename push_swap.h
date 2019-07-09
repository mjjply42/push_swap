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

struct      s_stack *initStack();
struct      s_node *initNode(int value);
struct      s_node  *initList(struct s_node *node, struct s_node *head);
void        toStack(int value, struct s_stack **A);
void        set_start(struct s_stack **A, struct s_stack **B, int *num_arr, int size);
void        SA(struct s_stack **A);
void        SB(struct s_stack **B);
void        swap(int *a, int *b);
void        print_stack(struct s_stack **Stack);
int         *initArray(char **list, int length);
int         *initArray(char **list, int length);
int         checkMax(int content, int *big);

#endif