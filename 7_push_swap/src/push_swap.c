/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:14:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/19 04:39:22 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

typedef struct s_dlist
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_dlist;

typedef struct s_list_i
{
	int				content;
	struct s_list_i	*next;
}					t_list_i;

typedef struct s_dbl_list_i
{
	int					content;
	struct s_dbl_list_i	*prev;
	struct s_dbl_list_i	*next;
}					t_dbl_list_i;

typedef struct s_stacks
{
	t_dbl_list_i	*stack_a;
	int				size_a;
	t_dbl_list_i	*stack_b;
	int				size_b;
}					t_stacks;

t_dbl_list_i	*ft_dbl_lst_i_new(int content)
{
	t_dbl_list_i	*newitem;

	newitem = malloc(sizeof(t_dbl_list_i));
	newitem->content = content;
	newitem->prev = NULL;
	newitem->next = NULL;
	return (newitem);
}

int	ft_dbl_lst_i_size(t_dbl_list_i *lst)
{
	int	count_items;

	if (lst == NULL)
		return (0);
	count_items = 1;
	while (lst->next != NULL)
	{
		count_items++;
		lst = lst->next;
	}
	return (count_items);
}

t_dbl_list_i	*ft_dbl_lst_i_last(t_dbl_list_i *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_dbl_lst_i_add_back(t_dbl_list_i **lst, t_dbl_list_i *new)
{
	t_dbl_list_i	*last_element;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_element = ft_dbl_lst_i_last(*lst);
		last_element->next = new;
		new->next = NULL;
	}
}

void	ft_dbl_lst_i_add_front(t_dbl_list_i **lst, t_dbl_list_i *new)
{
	new->next = *lst;
	*lst = new;
	return ;
}

void	free_stack(t_dbl_list_i *lst)
{
	t_dbl_list_i	*aux;

	while (lst->next)
	{
		aux = lst->next;
		free(lst);
		lst = aux;
	}
	free (lst);
}

int	main(int argc, char *argv[])
// TODO: FAZER VARIÁVEL 'GLOBAL' QUE GUARDA AS STACKS E TAL.
{
	t_stacks		stacks;
	int				i;
	t_dbl_list_i	*pivot;

	if (argc < 2)
		return (0);
	stacks.stack_a = NULL;
	i = 0;
	while (++i < argc)
		ft_dbl_lst_i_add_back(&stacks.stack_a, ft_dbl_lst_i_new(ft_atoi(argv[i])));
	pivot = stacks.stack_a;
	stacks.size_a = ft_dbl_lst_i_size(stacks.stack_a);
	i = -1;
	printf("stack a:\n");
	while (++i < stacks.size_a)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	free_stack(stacks.stack_a);
	stacks.stack_b = NULL;
	ft_dbl_lst_i_add_back(&stacks.stack_b, ft_dbl_lst_i_new(42));
	pivot = stacks.stack_b;
	stacks.size_b = ft_dbl_lst_i_size(stacks.stack_b);
	i = -1;
	printf("stack b:\n");
	while (++i < stacks.size_b)
	{
		printf("%i\n", pivot->content);
		pivot = pivot->next;
	}
	free_stack(stacks.stack_b);
	return (0);
}