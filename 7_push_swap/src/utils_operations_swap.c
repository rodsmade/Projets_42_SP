/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/23 14:48:06 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	t_dbl_list_i	*new_first;
	t_dbl_list_i	*new_second;

	if (ft_dbl_lst_i_size(stacks->stack_a) < 2)
		return ;
	new_first = stacks->stack_a->next;
	new_second = stacks->stack_a;
	stacks->stack_a = new_first;
	new_second->prev = new_first;
	new_first->prev = NULL;
	new_second->next = new_first->next;
	new_first->next = new_second;
	ft_putendl_fd("sa", 1);
	return ;
}

void	swap_b(t_stacks *stacks)
{
	t_dbl_list_i	*new_first;
	t_dbl_list_i	*new_second;
	t_dbl_list_i	*third;

	if (ft_dbl_lst_i_size(stacks->stack_b) < 2)
		return ;
	new_first = stacks->stack_b->next;
	new_second = stacks->stack_b;
	third = stacks->stack_b->next->next;
	stacks->stack_b = new_first;
	new_first->prev = NULL;
	new_first->next = new_second;
	new_second->prev = new_first;
	new_second->next = third;
	third->prev = new_second;
	ft_putendl_fd("sb", 1);
	return ;
}

void	swap_ab(t_stacks *stacks)
{
	t_dbl_list_i	*new_first;
	t_dbl_list_i	*new_second;

	if (ft_dbl_lst_i_size(stacks->stack_a) < 2
		&& ft_dbl_lst_i_size(stacks->stack_b) < 2)
		return ;
	if (ft_dbl_lst_i_size(stacks->stack_a) >= 2)
	{
		new_first = stacks->stack_a->next;
		new_second = stacks->stack_a;
		stacks->stack_a = new_first;
		new_second->prev = new_first;
		new_first->prev = NULL;
		new_second->next = new_first->next;
		new_first->next = new_second;
	}
	if (ft_dbl_lst_i_size(stacks->stack_a) >= 2)
	{
		new_first = stacks->stack_b->next;
		new_second = stacks->stack_b;
		stacks->stack_b = new_first;
		new_second->prev = new_first;
		new_first->prev = NULL;
		new_second->next = new_first->next;
		new_first->next = new_second;
	}
	ft_putendl_fd("ss", 1);
	return ;
}
