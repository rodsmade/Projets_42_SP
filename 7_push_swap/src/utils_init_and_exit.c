/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_and_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:43:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/02/02 04:06:33 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	return ;
}

static void	free_stack(t_dbl_list_i *lst)
{
	t_dbl_list_i	*aux;

	if (lst == NULL)
		return ;
	while (lst->next)
	{
		aux = lst->next;
		free(lst);
		lst = aux;
	}
	free(lst);
	return ;
}

void	free_stacks(t_stacks *stacks)
{
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
	return ;
}

void	error_exit(t_stacks *stacks)
{
	free_stacks(stacks);
	ft_putendl_fd("Error", 2);
	exit(0);
}
