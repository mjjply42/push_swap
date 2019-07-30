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

struct s_node	*find_spot(struct s_stack **b, int incoming)
{
	struct s_node	*tmp;
	int				*arr;
	int				i;

	i = 0;
	tmp = (*b)->stack;
	arr = make_arr(b, incoming);
	if (tmp->next == NULL)
	{
		free(arr);
		return (tmp);
	}
	//tmp = had_to(b, incoming, &arr);
	// while (i < (*b)->capacity + 1)
	// {
	// 	ft_printf("test1\n");
	// 	ft_printf("NUM: %i\n", arr[i]);
	// 	if (incoming == arr[0])
	// 	{
	// 		ft_printf("test2\n");
	// 		free(arr);
	// 		tmp = find_node(b, arr[i + 1]);
	// 		return (tmp);
	// 	}
	// 	if (arr[i] == incoming)
	// 	{
	// 		if (i == (*b)->capacity)
	// 		{
	// 			ft_printf("test3\n");
	// 			free(arr);
	// 			tmp = find_node(b, arr[i - 1]);
	// 			return (tmp);
	// 		}
	// 		tmp = find_node(b, arr[i + 1]);
	// 		{
	// 			ft_printf("test4\n");
	// 			free(arr);
	// 			return (tmp);
	// 		}
	// 	}
	// 	i++;
	// }
	free(arr);
	return (tmp);
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
