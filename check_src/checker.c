#include "../checker.h"
#include "../push_swap.h"

char    *setOrders()
{
    char *orders = NULL;
    char buffer[BUFF_SIZE + 1];

    while((read(STDIN_FILENO, buffer, BUFF_SIZE)) > 0)
    {
        if(orders == NULL)
            orders = ft_strdup(buffer);
        else
            orders = ft_strjoin(orders,buffer);
        ft_memset(buffer, 0, BUFF_SIZE);
    }
    return orders;
}

void    pick_command(struct s_stack **A,struct s_stack **B,char *command)
{
    if(ft_strcmp(command,"pa") == 0)
        PA(B,A);
    else if(ft_strcmp(command,"pb") == 0)
        PB(A,B);
    else if(ft_strcmp(command,"sa") == 0)
        SA(A);
    else if(ft_strcmp(command,"sb") == 0)
        SB(A,B);
    else if(ft_strcmp(command,"ss") == 0)
        SS(A,B);
    else if(ft_strcmp(command,"ra") == 0)
        RA(A);
    else if(ft_strcmp(command,"rb") == 0)
        RB(A,B);
    else if(ft_strcmp(command,"rr") == 0)
        RR(A,B);
    else if(ft_strcmp(command,"rra") == 0)
        RRA(A);
    else if(ft_strcmp(command,"rrb") == 0)
        RRB(A,B);
    else if(ft_strcmp(command,"rrr") == 0)
        RRR(A,B);
    else
        terminate_program();
}
void    run_commands(struct s_stack **A,struct s_stack **B,char *orders)
{
    int count;
    int i;
    char *command;

    command = NULL;
    count = 0;
    i = 0;
    while(orders[i])
    {
        check_formatting(orders[i-1],orders[i],orders[1+1]);
        if(orders[i] == '\n' || orders[i] == '\0')
        {
            command = ft_strnew(sizeof(char)*count);
            ft_memcpy(command,(orders + (i) - count),count);
            count = -1;
            pick_command(A,B,command);
            free(command);
        }
        count++;
        i++;
    }
}

void    checker(struct s_stack *A,struct s_stack *B)
{
    char *orders;

    orders = setOrders();
    run_commands(&A,&B,orders);
    //print_set(&A,&B);
    if(isSorted(&A))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}

int     main(int ac,char **av)
{
    int length;
    int *num_list;
    struct s_stack *A;
    struct s_stack *B;
    
    if(ac < 2)
    {
        ft_printf("OK\n");
        return 1;
    }
    length = ac-1;
    A = initStack();
    B = initStack();
    num_list = initArray(av, length);
    check_doubles(num_list,length);
    set_datum(&A, num_list, length);
    checker(A,B);

    return 1;
}