/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:03:43 by majones           #+#    #+#             */
/*   Updated: 2019/07/24 23:04:33 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		set_sort_status(struct s_stack **a)
{
	int				num;
	struct s_node	*tmp;

	num = 0;
	tmp = (*a)->stack;
	while (tmp->value != ((*a)->max_a))
		tmp = tmp->next;
	tmp->sorted = 1;
	while (tmp->prev->value == get_next_value(a, tmp->value) && tmp->prev != NULL)
	{
		tmp = tmp->prev;
		tmp->sorted = 1;
	}
	return (num);
}

void	part_combine(struct s_stack **a, struct s_stack **b)
{
	struct s_node *tmp;

	tmp = (*b)->stack;
	to_end(&tmp);
	while (tmp->value > (*b)->stack->value)
	{
		tmp = tmp->prev;
		rrb(a, b);
	}
}

void	align_to_front(struct s_stack **a, struct s_stack **b)
{
	struct s_node *tmp;

	tmp = (*a)->stack;
	while ((*a)->stack->sorted != 1 || (*a)->stack->value != (*a)->max_a ||
			(*a)->stack->value != get_next_value(a, (*a)->max_a))
	{
		if ((*b)->capacity == 2)
			if ((*b)->stack->value < (*b)->stack->next->value)
				sb(a, b);
		prep_b(a, b, (*a)->stack->value);
		pb(a, b);
	}
	while ((*a)->stack->value == get_next_value(a, (*a)->max_a)
	&& ((*a)->stack->next != NULL
	&& (*a)->stack->next->value != (*a)->max_a))
	{
		if ((*b)->capacity == 2)
			if ((*b)->stack->value < (*b)->stack->next->value)
				sb(a, b);
		sa(a);
		prep_b(a, b, (*a)->stack->value);
		pb(a, b);
	}
	part_combine(a, b);
}

void	final_move(struct s_stack **a, struct s_stack **b)
{
	struct s_node *tmp;

	tmp = (*a)->stack;
	to_end(&tmp);
	while (!is_empty(b))
	{
		if ((*a)->stack->value < (*b)->stack->value)
		{
			ra(a);
			tmp = tmp->next;
		}
		else if ((*b)->stack->value < tmp->value && tmp->value != (*a)->max_a)
		{
			tmp = tmp->prev;
			rra(a);
		}
		if (is_sorted(a) && !is_sorted(b))
			while ((*b)->stack->value != find_big(b))
				rrb(a, b);
		pa(b, a);
		(*a)->stack->sorted = 1;
	}
}

int		*make_arr(struct s_stack **b, int incoming)
{
	int				i;
	int				*arr;
	struct s_node	*tmp;

	tmp = (*b)->stack;
	i = 0;
	arr = malloc(sizeof(int) * (*b)->capacity + 1);
	arr[i] = incoming;
	i++;
	while (i < (*b)->capacity + 1)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	quicksort(arr, 0, (*b)->capacity);
	return (arr);
}
