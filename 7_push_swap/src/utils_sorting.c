/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:17:07 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/25 14:15:42 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: DELETAR ESSE TREM																					a
#include <stdio.h>
/*
 * top = list's first element
 * bottom = list's last element
 * ascending order = ascending bottom up
 */
int	is_sorted_asc(t_dbl_list_i *stack)
{
	t_dbl_list_i	*pivot;

	pivot = stack;
	while (pivot->next != NULL)
	{
		if (pivot->content > pivot->next->content)
			return (0);
		pivot = pivot->next;
	}
	return (1);
}

/*
 * top = list's first element
 * bottom = list's last element
 * descending order = descending top down
 */
int	is_sorted_desc(t_dbl_list_i *stack)
{
	t_dbl_list_i	*pivot;

	pivot = stack;
	while (pivot->next != NULL)
	{
		if (pivot->content < pivot->next->content)
			return (0);
		pivot = pivot->next;
	}
	return (1);
}

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

void	check_if_b_is_sorted_and_reposition(t_stacks *stacks)
{
	int				count;
	t_dbl_list_i	*pivot;

	count = 0;
	if (stacks->stack_b->content > ft_dbl_lst_i_last(stacks->stack_b)->content)
		count++;
	pivot = stacks->stack_b;
	while (pivot->next)
	{
		if (pivot->content < pivot->next->content)
			count++;
		pivot = pivot->next;
	}
	pivot = stacks->stack_b;
	if (count == 1)
	{
		while (stacks->stack_b->content < stacks->stack_b->next->content)
			rotate_b(stacks);
	}
	return ;
}

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
	check_if_b_is_sorted_and_reposition(stacks);
}

void	strategy_part_three(t_stacks *stacks)
{
	if (is_sorted_desc(stacks->stack_b))
	{
		while (stacks->stack_b)
			push_a(stacks);
		return ;
	}
	// if (ft_dbl_lst_i_size(stacks->stack_a) == 0)
	// while (ft_dbl_lst_i_size(stacks->stack_b))
	// {
	// 	if (stacks->stack_b->content < stacks->stack_a->content)
	// 		push_a(stacks);
	// }
	return ;
}