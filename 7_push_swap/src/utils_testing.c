/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_testing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:30:19 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/23 15:31:28 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_stacks *stacks)
{
	t_dbl_list_i	*pivot;

	// prints stack a
	pivot = stacks->stack_a;
	printf("stack a:\t(size: %i)\n", ft_dbl_lst_i_size(stacks->stack_a));
	while (pivot)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	// prints stack b
	pivot = stacks->stack_b;
	printf("stack b:\t(size: %i)\n", ft_dbl_lst_i_size(stacks->stack_b));
	while (pivot)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	return ;
}

void	print_stacks_ptrs(t_stacks *stacks)
{
	t_dbl_list_i	*pivot;

	// prints stack a
	pivot = stacks->stack_a;
	printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	printf("stack a:\t(size: %i)\n", ft_dbl_lst_i_size(stacks->stack_a));
	printf("prev:\t\tcurr (cont)\tnext:\n");
	while (pivot)
	{
		printf("%p\t%p(%i)\t%p\n", pivot->prev, pivot, pivot->content, pivot->next);
		pivot = pivot->next;
	}
	// prints stack b
	pivot = stacks->stack_b;
	printf("stack b:\t(size: %i)\n", ft_dbl_lst_i_size(stacks->stack_b));
	while (pivot)
	{
		printf("%p\t%p(%i)\t%p\n", pivot->prev, pivot, pivot->content, pivot->next);
		pivot = pivot->next;
	}
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	return ;
}

