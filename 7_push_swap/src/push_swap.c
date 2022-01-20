/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:14:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/19 22:35:47 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	initialise(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = ft_dbl_lst_i_size(stacks->stack_a);
	stacks->size_b = ft_dbl_lst_i_size(stacks->stack_b);
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
	int	i;
	t_dbl_list_i	*pivot;

	// prints stack a
	pivot = stacks->stack_a;
	i = -1;
	printf("stack a:\t(size: %i)\n", stacks->size_a);
	while (++i < stacks->size_a)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	// prints stack b
	pivot = stacks->stack_b;
	i = -1;
	printf("stack b:\t(size: %i)\n", stacks->size_b);
	while (++i < stacks->size_b)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	return ;
}

int	validate(char *argv, t_stacks *stacks)
{
	// int	i;
	
	// i = 0;
	// while (++i < argc)
	// {
	// 	if (is_valid_input(argv[i], &stacks))
	// 		ft_dbl_lst_i_add_back(&stacks.stack_a,
	// 				ft_dbl_lst_i_new(ft_atoi(argv[i])));
	// }
	// stacks.size_a = ft_dbl_lst_i_size(stacks.stack_a);
	if (!ft_isdigit_str(argv))
	{
		free_stack(stacks->stack_a);
		ft_putendl_fd("Error\n", 1);
		exit(-1);
	}

}

void	sort(t_stacks *stacks)
{
	free_stack(stacks->stack_a);
	free_stack(stacks->stack_b);
}

int	main(int argc, char *argv[])
{
	t_stacks		stacks;

	if (argc == 2)
	{
		ft_putendl_fd("Error", 1);
		exit(-1);
	}
	if (argc > 2)
	{
		validate(argv, &stacks);
		sort(&stacks);
	}
	return (0);
}