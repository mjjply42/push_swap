#include "../push_swap.h"

void    SS(struct s_stack **A, struct s_stack **B)
{
    SA(A);
    SB(A,B);
    add_command(A,"ss");
}

void    RR(struct s_stack **A, struct s_stack **B)
{
    RA(A);
    RB(A,B);
    add_command(A,"rr");
}

void    RRR(struct s_stack **A, struct s_stack **B)
{
    RRA(A);
    RRB(A,B);
    add_command(A,"rrr");
}