/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:14:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/22 16:15:53 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	initialise(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	return ;
}

void	free_stack(t_dbl_list_i *lst)
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
	free (lst);
}

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

void	error_exit(t_stacks *stacks)
{
	free_stack(stacks->stack_a);
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	checks_duplicates(t_stacks *stacks)
{
	t_dbl_list_i	*pivot;
	t_dbl_list_i	*duplicate;

	pivot = stacks->stack_a;
	while (pivot->next != NULL)
	{
		duplicate = pivot->next;
		while (duplicate->next != NULL)
		{
			if (pivot->content == duplicate->content)
				return (0);
			duplicate = duplicate->next;
		}
		if (pivot->content == duplicate->content)
			return (0);
		pivot = pivot->next;
	}
	if (pivot->content == pivot->prev->content)
		return (0);
	return (1);
}

void	validate_input(char *argv[], t_stacks *stacks)
{
	int	i;

	initialise(stacks);
	i = 0;
	while (argv[++i])
	{
		if (!ft_isnumeric_s(argv[i]))
			error_exit(stacks);
		if (ft_atoli(argv[i]) > INT_MAX)
			error_exit(stacks);
		ft_dbl_lst_i_add_back(&stacks->stack_a,
			ft_dbl_lst_i_new(ft_atoi(argv[i])));
	}
	printf("all args passed check\n");
	if (!checks_duplicates(stacks))
		error_exit(stacks);
	printf("no duplicates found\n");
	return ;
}

int	is_sorted(t_stacks *stacks)
{
	t_dbl_list_i	*pivot;

	pivot = stacks->stack_a;
	while (pivot->next != NULL)
	{
		if (pivot->content > pivot->next->content)
			return (0);
		pivot = pivot->next;
	}
	free_stack(stacks->stack_a);
	return (1);
}

void	sort(t_stacks *stacks)
{
	print_stacks(stacks);
	printf("stack needs sorting!\n. . . starting sorting RN\n");
	push_b(stacks);
	push_b(stacks);
	push_b(stacks);
	print_stacks(stacks);
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
}

int	main(int argc, char *argv[])
{
	t_stacks		stacks;

	if (argc > 2)
	{
		validate_input(argv, &stacks);
		if (!is_sorted(&stacks))
			sort(&stacks);
	}
	return (0);
}
