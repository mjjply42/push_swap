/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 01:45:39 by majones           #+#    #+#             */
/*   Updated: 2019/07/25 01:45:44 by majones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFF_SIZE 1
# include <unistd.h>

int		check_doubles(int *num_arr, int length);
int		check_int(char *str);
void	check_formatting(char prev_char, char curr_char, char next_char);
int		check_no_let_error(int ac, char **av);
void	terminate_program();
#endif
