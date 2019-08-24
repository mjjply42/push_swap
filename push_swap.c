/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 05:42:25 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 05:42:29 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void	set_cue(struct s_stack **a, int *num_arr)
{
	int i;

	i = (*a)->max_a;
	while (num_arr[i] != 1 && i > 0)
		i--;
	if (num_arr[i] == 1)
	{
		(*a)->end = (i) * -1;
		return ;
	}
	while (num_arr[i] != 2 && i < (*a)->max_a)
		i++;
	(*a)->end = i;
}

void	other_end(struct s_stack **a, struct s_stack **b, int next_up)
{
	if ((*a)->stack->value != (*a)->max_a)
	{
		if ((*a)->stack->value == next_up &&
			(*a)->stack->next->value == (*a)->max_a)
		{
			ra(a);
			(*a)->tail = (*a)->tail->next;
		}
		else if ((*a)->stack->value == next_up && (*a)->stack->sorted == 0)
			sa(a);
		else
		{
			prep_b(a, b, (*a)->stack->value);
			pb(a, b);
		}
	}
	else
	{
		ra(a);
		(*a)->tail = (*a)->tail->next;
	}
}

void	high_end(struct s_stack **a, struct s_stack **b, int side)
{
	int next_up;

	next_up = get_next_value(a, (*a)->max_a);
	while ((*a)->tail->value != (*a)->max_a)
	{
		if (side == 1)
		{
			(*a)->tail = (*a)->tail->prev;
			rra(a);
		}
		else
			other_end(a, b, next_up);
	}
}

void	push_swap(struct s_stack **a, struct s_stack **b)
{
	int				side;
	struct s_node	*tmp;

	tmp = (*a)->stack;
	to_end(&tmp);
	(*a)->tail = tmp;
	side = find_side(a, (*a)->max_a);
	high_end(a, b, side);
	set_sort_status(a);
	align_to_front(a, b);
	final_move(a, b);
}

int		main(int ac, char **av)
{
	int				length;
	int				*num_list;
	struct s_stack	*a;
	struct s_stack	*b;
    int             place;

	length = ac - 1;
	check_no_let_error(ac, av);
	a = init_stack();
	b = init_stack();
	num_list = init_array(av, length);
	check_doubles(num_list, length);
	set_datum(&a, num_list, length);
    quicksort(num_list, 0, (a->capacity - 1));
    print_array(a->capacity, num_list);
    if (a->capacity > 9)
    {
        ////////////NEED to accomodate sorting after a sorted portion is in A.
        ////////////Same approach, but slightly modified. I need to check 5
        ////////////from the front, and up to 5 unsorted back values. If values
        ////////////can be immediately added as a direct sort to the back sorted end,
        ////////////add away. If there are other unsorted numbers in the way of a direct sort,
        ////////////manuever those to B, move next piece, and move back values if needed
        while (is_sorted(&a) == 0)
        {
            if (has_order(a))
                modified_sort(&a, &b, num_list);
        ft_printf("fyguhijokpl[;\n");
        if (a->capacity < 6 && a->capacity >= 2)
            if (a->stack->value < a->stack->next->value)
                sa(&a);
        ft_printf("ifdsfdghjk;\n");
        place = find_good_grab(&a, num_list);
        pull_side(place, &a);
        handle_move(&a, &b);
        print_stack(&a);
        print_stack(&b);
        }
        while (b->stack->value != find_small(&b))
            move(&a, &b, find_side(&b, find_small(&b)));
        while (b->capacity > 0)
        {
            //print_stack(&b);
            ft_printf("CAP: %i\n", b->capacity);
            //if (a->capacity > 0)
            //    ra(&a);
            b->capacity--;
            //pa(&b, &a);
        }
        //ra(&a);
        ft_printf("A:\n");
        print_stack(&a);
        ft_printf("B:\n");
        print_stack(&b);
        print_moves(&a);
    }
    //else
    //calculate

	/*free_num_list(num_list);
	if (is_sorted(&a) == 1)
		return (1);
	push_swap(&a, &b);
	while (!is_sorted(&a))
		rra(&a);
	print_moves(&a);
	free_stack_struct(a);
	free_stack_struct(b);*/
	return (1);
}
