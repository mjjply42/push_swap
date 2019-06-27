#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/////////////////////////////////////////////
/////*Structs for Stack and Stack Nodes*/////
/////////////////////////////////////////////
struct s_node
{
    int value;
    struct s_node *next;
    struct s_node *prev;
};

struct  s_stack
{
    int capacity;
    int max;
    int min;
    struct s_node *stack;
};

struct s_stack *initStack();
struct s_node *initNode(int value);
int *initList(int *num_list);

#endif