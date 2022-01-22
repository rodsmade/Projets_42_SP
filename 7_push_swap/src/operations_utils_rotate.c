/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:45:08 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/22 16:07:55 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	t_dbl_list_i	*detach;

	if (stacks->stack_a == NULL || stacks->stack_a->next == NULL)
		return ;
	detach = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	if (stacks->stack_a)
		stacks->stack_a->prev = NULL;
	ft_dbl_lst_i_add_back(&stacks->stack_a, detach);
	ft_putendl_fd("ra", 1);
	return ;
}

void	rotate_b(t_stacks *stacks)
{
	t_dbl_list_i	*detach;

	if (stacks->stack_b == NULL || stacks->stack_b->next == NULL)
		return ;
	detach = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	if (stacks->stack_b)
		stacks->stack_b->prev = NULL;
	ft_dbl_lst_i_add_back(&stacks->stack_b, detach);
	ft_putendl_fd("rb", 1);
	return ;
}

void	rotate_ab(t_stacks *stacks)
{
	t_dbl_list_i	*detach;

	if (stacks->stack_a == NULL || stacks->stack_a->next == NULL)
		return ;
	detach = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	if (stacks->stack_a)
		stacks->stack_a->prev = NULL;
	ft_dbl_lst_i_add_back(&stacks->stack_a, detach);
	if (stacks->stack_b == NULL || stacks->stack_b->next == NULL)
		return ;
	detach = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	if (stacks->stack_b)
		stacks->stack_b->prev = NULL;
	ft_dbl_lst_i_add_back(&stacks->stack_b, detach);
	ft_putendl_fd("rr", 1);
	return ;
}
