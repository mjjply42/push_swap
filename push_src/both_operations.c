#include "../push_swap.h"

//Operations SA and SB
void    SS(struct s_stack **A, struct s_stack **B)
{
    SA(A);
    SB(A,B);
    add_command(A,"ss");
}

//Operations RA and RB
void    RR(struct s_stack **A, struct s_stack **B)
{
    RA(A);
    RB(A,B);
    add_command(A,"rr");
}

//Operations RRA and RRB
void    RRR(struct s_stack **A, struct s_stack **B)
{
    RRA(A);
    RRB(A,B);
    add_command(A,"rrr");
}