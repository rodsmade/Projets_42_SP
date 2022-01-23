/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:17:07 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/23 15:35:29 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements_b(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->stack_b->content;
	second = stacks->stack_b->next->content;
	third = stacks->stack_b->next->next->content;
	if (first < second && first < third && second < third)
	{
		swap_b(stacks);
		reverse_rotate_b(stacks);
	}
	if (first < second && first < third && second > third)
		rotate_b(stacks);
	if (first > second && first < third && second < third)
		reverse_rotate_b(stacks);
	if (first < second && first > third && second > third)
		swap_b(stacks);
	if (first > second && first > third && second < third)
	{
		swap_b(stacks);
		rotate_b(stacks);
	}	
	return;
}
