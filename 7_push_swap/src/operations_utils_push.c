/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_push.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:43:30 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/19 20:46:58 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
// detaches stack b's head and inserts it on top of stack a
{
	t_dbl_list_i	*detach;

	if (stacks->size_b <= 0)
		return ;
	detach = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	if (stacks->stack_b)
		stacks->stack_b->prev = NULL;
	stacks->size_b--;
	ft_dbl_lst_i_add_front(&stacks->stack_a, detach);
	stacks->size_a++;
	ft_putendl_fd("pa", 1);
	return ;
}

void	push_b(t_stacks *stacks)
// detaches stack a's head and inserts it on top of stack b
{
	t_dbl_list_i	*detach;

	if (stacks->size_a == 0)
		return ;
	detach = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	if (stacks->stack_a)
		stacks->stack_a->prev = NULL;
	stacks->size_a--;
	ft_dbl_lst_i_add_front(&stacks->stack_b, detach);
	stacks->size_b++;
	ft_putendl_fd("pb", 1);
	return ;
}
