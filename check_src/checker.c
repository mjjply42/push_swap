/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 04:55:07 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 04:55:11 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include "../push_swap.h"

char	*set_orders(void)
{
	char *orders;
	char *test;
	char buffer[BUFF_SIZE + 1];

	orders = NULL;
	test = NULL;
	while ((read(STDIN_FILENO, buffer, BUFF_SIZE)) > 0)
	{
		if (orders == NULL)
			orders = ft_strdup(buffer);
		else
			test = ft_strjoin((test == NULL ? orders : test), buffer);
		ft_memset(buffer, 0, BUFF_SIZE);
	}
	return (test == NULL ? orders : test);
}

void	pick_command(struct s_stack **a, struct s_stack **b, char *command)
{
	if (ft_strcmp(command, "pa") == 0)
		pa(b, a);
	else if (ft_strcmp(command, "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(command, "sa") == 0)
		sa(a);
	else if (ft_strcmp(command, "sb") == 0)
		sb(a, b);
	else if (ft_strcmp(command, "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(command, "ra") == 0)
		ra(a);
	else if (ft_strcmp(command, "rb") == 0)
		rb(a, b);
	else if (ft_strcmp(command, "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(command, "rra") == 0)
		rra(a);
	else if (ft_strcmp(command, "rrb") == 0)
		rrb(a, b);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(a, b);
	else
		terminate_program();
}

void	run_commands(struct s_stack **a, struct s_stack **b, char *orders)
{
	int	count;
	int i;
	char*command;

	command = NULL;
	count = 0;
	i = 0;
	while (orders[i])
	{
		check_formatting(orders[i - 1], orders[i], orders[1 + 1]);
		if (orders[i] == '\n' || orders[i] == '\0')
		{
			command = ft_strnew(sizeof(char) * count);
			ft_memcpy(command, (orders + (i) - count), count);
			count = -1;
			pick_command(a, b, command);
			free(command);
		}
		count++;
		i++;
	}
}

void	checker(struct s_stack *a, struct s_stack *b)
{
	char *orders;

	if (is_sorted(&a))
		return ;
	orders = set_orders();
	run_commands(&a, &b, orders);
	free(orders);
	if (is_sorted(&a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int		main(int ac, char **av)
{
	int				length;
	int				*num_list;
	struct s_stack	*a;
	struct s_stack	*b;

	if (ac < 2)
		return (1);
	length = ac - 1;
	a = init_stack();
	b = init_stack();
	num_list = init_array(av, length);
	check_doubles(num_list, length);
	set_datum(&a, num_list, length);
	free_num_list(num_list);
	checker(a, b);
	free_stack_struct(a);
	free_stack_struct(b);
	return (1);
}
