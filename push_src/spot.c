/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:20:43 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 03:20:45 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				find_spot(struct s_stack **b, int incoming)
{
	struct s_node	*tmp;
	int				*arr;
	int				i;
	int				spot;

	i = 0;
	tmp = (*b)->stack;
	arr = malloc(sizeof(int) * (*b)->capacity);
	zero_out(arr, (*b)->capacity);
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	print_array((*b)->capacity, arr);
	quicksort(arr, 0, (*b)->capacity - 1);
	print_array((*b)->capacity, arr);
	i = 0;
	spot = arr[0];
	ft_printf("BIGGG: %i\n", find_big(b));
	if (find_big(b) < incoming)
	{
		ft_printf("SHIT\n");
		return (find_small(b));
	}
	while (incoming > spot)
	{
		spot = arr[i];
		i++;
	}
	return (spot);
}

void			to_spot3(struct s_stack **a, struct s_stack **b,
						struct s_node **tmp, int tag)
{
	if (tag == 1)
	{
		rb(a, b);
		to_end(tmp);
	}
	else if (tag == 0)
	{
		rrb(a, b);
		to_end(tmp);
	}
}

void			to_spot2(struct s_stack **a, struct s_stack **b,
						struct s_node **tmp, struct s_node *spot)
{
	while (spot != (*tmp))
	{
		rrb(a, b);
		to_end(tmp);
	}
}

void			to_spot(struct s_stack **a, struct s_stack **b,
						struct s_node **tmp, struct s_node *spot)
{
	while (spot != (*tmp))
	{
		(*tmp) = (*tmp)->prev;
		rrb(a, b);
	}
}

void			set_pos(struct s_stack **a, struct s_stack **b,
						struct s_node *spot, int incoming)
{
	struct s_node *tmp;

	tmp = (*b)->stack;
	to_end(&tmp);
	if (incoming < (*b)->stack->value && incoming < tmp->value)
	{
		to_spot2(a, b, &tmp, spot);
		if (incoming > spot->value)
			rrb(a, b);
	}
	else if (incoming < (*b)->stack->value && incoming > tmp->value)
		to_spot(a, b, &tmp, spot);
	else if (incoming > (*b)->stack->value && incoming > tmp->value)
	{
		to_spot(a, b, &tmp, spot);
		if (incoming > spot->value)
			rb(a, b);
		else
			return ;
	}
	else if (incoming > (*b)->stack->value && incoming < tmp->value)
		to_spot(a, b, &tmp, spot);
}
