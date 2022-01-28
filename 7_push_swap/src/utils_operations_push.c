/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:43:30 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/28 13:51:32 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// detaches stack b's head and inserts it on top of stack a
void	push_a(t_stacks *stacks)
{
	t_dbl_list_i	*detach;

	if (!stacks->stack_b)
		return ;
	detach = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	if (stacks->stack_b)
		stacks->stack_b->prev = NULL;
	ft_dbl_lst_i_add_front(&stacks->stack_a, detach);
	ft_putendl_fd("pa", 1);
	return ;
}

// detaches stack a's head and inserts it on top of stack b
void	push_b(t_stacks *stacks)
{
	t_dbl_list_i	*detach;

	if (!stacks->stack_a)
		return ;
	detach = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	if (stacks->stack_a)
		stacks->stack_a->prev = NULL;
	ft_dbl_lst_i_add_front(&stacks->stack_b, detach);
	ft_putendl_fd("pb", 1);
	return ;
}
