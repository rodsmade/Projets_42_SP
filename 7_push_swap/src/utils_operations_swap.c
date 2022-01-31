/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_operations_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:47:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/31 19:07:39 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	int	aux;

	aux = stacks->stack_a->content;
	stacks->stack_a->content = stacks->stack_a->next->content;
	stacks->stack_a->next->content = aux;
	ft_putendl_fd("sa", 1);
	return ;
}

void	swap_b(t_stacks *stacks)
{
	int	aux;

	aux = stacks->stack_b->content;
	stacks->stack_b->content = stacks->stack_b->next->content;
	stacks->stack_b->next->content = aux;
	ft_putendl_fd("sb", 1);
	return ;
}

void	swap_ab(t_stacks *stacks)
{
	int	aux;

	if (ft_dbl_lst_i_size(stacks->stack_a) < 2
		&& ft_dbl_lst_i_size(stacks->stack_b) < 2)
		return ;
	if (ft_dbl_lst_i_size(stacks->stack_a) >= 2)
	{
		aux = stacks->stack_a->content;
		stacks->stack_a->content = stacks->stack_a->next->content;
		stacks->stack_a->next->content = aux;
	}
	if (ft_dbl_lst_i_size(stacks->stack_b) >= 2)
	{
		aux = stacks->stack_b->content;
		stacks->stack_b->content = stacks->stack_b->next->content;
		stacks->stack_b->next->content = aux;
	}
	ft_putendl_fd("ss", 1);
	return ;
}
