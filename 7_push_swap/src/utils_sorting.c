/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:17:07 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/28 13:49:45 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * top = list's first element
 * ascending order = ascending top down
 * an empty stack is considered unsorted
 */
int	is_sorted_asc(t_dbl_list_i *stack)
{
	t_dbl_list_i	*pivot;

	if (!stack)
		return (0);
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
 * descending order = descending top down
 * an empty stack is considered unsorted
 */
int	is_sorted_desc(t_dbl_list_i *stack)
{
	t_dbl_list_i	*pivot;

	if (!stack)
		return (0);
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
	return ;
}

void	strategy_part_one(t_stacks *stacks)
{
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	sort_three_elements_b(stacks);
}

void	rotate_b_biggest_element_on_top(t_stacks *stacks)
{
	int				position;
	int				halfway;
	int				list_size;
	t_dbl_list_i	*pivot;

	position = 1;
	halfway = ft_dbl_lst_i_size(stacks->stack_b) / 2;
	list_size = ft_dbl_lst_i_size(stacks->stack_b);
	pivot = stacks->stack_b;
	while (pivot->content != stacks->biggest_element)
	{
		position++;
		pivot = pivot->next;
	}
	if (position == 1)
		return ;
	if (position <= halfway)
	{
		while (--position)
			rotate_b(stacks);
	}
	else
	{
		while ((list_size - position) >= 0)
		{
			reverse_rotate_b(stacks);
			position++;
		}
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
		if (ft_dbl_lst_i_size(stacks->stack_a) > 0)
			moves_allowed++;
	}
	rotate_b_biggest_element_on_top(stacks);
}

int	done_sorting_b(t_stacks *stacks)
{
	if (is_sorted_desc(stacks->stack_b))
	{
		while (stacks->stack_b)
			push_a(stacks);
		return (1);
	}
	return (0);
}

void	strategy_part_three(t_stacks *stacks)
{
	while (stacks->stack_b)
	{
		if (!stacks->stack_a)
			push_a(stacks);
		else if (stacks->stack_a->content > stacks->stack_b->content)
		{
			if (stacks->stack_b->next
				&& stacks->stack_b->content < stacks->stack_b->next->content)
			{
				swap_b(stacks);
				if (stacks->stack_a->content < stacks->stack_b->content)
					break ;
			}
			push_a(stacks);
		}
		else
		{
			push_b(stacks);
			swap_b(stacks);
		}
	}
	if (stacks->stack_b)
		strategy_part_three(stacks);
	return ;
}
