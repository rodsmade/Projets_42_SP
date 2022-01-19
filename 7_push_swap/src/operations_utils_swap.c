/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/19 20:47:29 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	t_dbl_list_i	*new_first;
	t_dbl_list_i	*new_second;

	if (stacks->size_a < 2)
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

	if (stacks->size_b < 2)
		return ;
	new_first = stacks->stack_b->next;
	new_second = stacks->stack_b;
	stacks->stack_b = new_first;
	new_second->prev = new_first;
	new_first->prev = NULL;
	new_second->next = new_first->next;
	new_first->next = new_second;
	ft_putendl_fd("sb", 1);
	return ;
}

void	swap_ab(t_stacks *stacks)
{
	t_dbl_list_i	*new_first;
	t_dbl_list_i	*new_second;

	if (stacks->size_a < 2)
		return ;
	new_first = stacks->stack_a->next;
	new_second = stacks->stack_a;
	stacks->stack_a = new_first;
	new_second->prev = new_first;
	new_first->prev = NULL;
	new_second->next = new_first->next;
	new_first->next = new_second;
	new_first = stacks->stack_b->next;
	new_second = stacks->stack_b;
	stacks->stack_b = new_first;
	new_second->prev = new_first;
	new_first->prev = NULL;
	new_second->next = new_first->next;
	new_first->next = new_second;
	ft_putendl_fd("ss", 1);
	return ;
}
