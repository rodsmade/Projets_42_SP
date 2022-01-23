/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:17:07 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/23 17:53:31 by roaraujo         ###   ########.fr       */
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

void	strategy_part_one(t_stacks *stacks)
{
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	sort_three_elements_b(stacks);
}

// TODO: DELETAR ESSE TREM																					a
#include <stdio.h>
void	strategy_part_two(t_stacks *stacks)
{
	int	moves_allowed;

	moves_allowed = ft_dbl_lst_i_size(stacks->stack_b);
	while (ft_dbl_lst_i_size(stacks->stack_a) > 0 && moves_allowed > 0)
	{
		while (moves_allowed > 0 && ft_dbl_lst_i_size(stacks->stack_a) > 0)
		{
			if (stacks->stack_a->content > stacks->stack_b->content)
			{
				push_b(stacks);
				moves_allowed++;
			}
			else
			{
				rotate_b(stacks);
				moves_allowed--;
			}
		}
		push_b(stacks);
		moves_allowed++;
	}
}
