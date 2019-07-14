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

struct      t_list
{
    char    *command;
    struct  t_list *next;
};

struct      s_stack
{
    int     capacity;
    int     max_a;
    int     end;
    struct  s_node *tail;
    struct  t_list *list;
    struct  s_node *pivot;
    struct  s_node *stack;
};

struct      s_node *pop(struct s_stack **st);
struct      s_stack *initStack();
struct      s_node *initNode(int value);
struct      s_node  *splitter(struct s_stack **A, struct s_stack **B);
struct      s_node   *setB_Tail(struct s_stack **B);
void        sorter(struct s_stack **A, struct s_stack **B,int *num_arr);
void        stripper(struct s_stack **A,struct s_stack **B,int *num_arr);
void        setter(struct s_stack **A,struct s_stack **B,int *num_arr,int *index);
void        seeker(struct s_stack **A,struct s_stack **B,int *num_arr,int *index);
void        push(struct s_stack **st, struct s_node *node);
void        toStack(int value, struct s_stack **A);
void        setCue(struct s_stack **A,int *num_arr);
void        set_datum(struct s_stack **A, int *num_arr, int size);
void        SA(struct s_stack **A);
void        SB(struct s_stack **A,struct s_stack **B);
void        SS(struct s_stack **A, struct s_stack **B);
void        PB(struct s_stack **A, struct s_stack **B);
void        PA(struct s_stack **B, struct s_stack **A);
void        RA(struct s_stack **A);
void        RB(struct s_stack **A,struct s_stack **B);
void        RR(struct s_stack **A, struct s_stack **B);
void        RRA(struct s_stack **A);
void        RRB(struct s_stack **A,struct s_stack **B);
void        RRR(struct s_stack **A, struct s_stack **B);
void        swap(int *a, int *b);
void        print_stack(struct s_stack **Stack);
void        print_set(struct s_stack **A, struct s_stack **B);
void        print_moves(struct s_stack **A);
void        initList(struct t_list **list, char *str);
void        add_command(struct s_stack **A,char *command);
void        push_swap(struct s_stack **A, struct s_stack **B);
int         checkA_Stack(struct s_stack **A,int *num_arr,int *index);
int         checkB_Match(struct s_stack **B,int *index);
int         checkA_Match(struct s_stack **A,int *index);
int         checkMatch(struct s_stack **A,struct s_stack **B,int *index);
void        checkB_Stack(struct s_stack **A, struct s_stack **B,int *index);
int         *initArray(char **list, int length);
int         checkMax(int content, int *big);
int         isSorted(struct s_stack **A);
int         checkNext(int *num_arr,struct s_stack **A);
int         isEmpty(struct s_stack **stack);
void        set_count_array(struct s_stack **A,int *num_arr);

#endif