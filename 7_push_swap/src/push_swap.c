/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:14:21 by roaraujo          #+#    #+#             */
/*   Updated: 2022/01/19 01:38:44 by roaraujo         ###   ########.fr       */
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
{
	int				i;
	int				lst_size;
	t_dbl_list_i	*stack_a;
	t_dbl_list_i	*pivot;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	i = 0;
	while (++i < argc)
		ft_dbl_lst_i_add_back(&stack_a, ft_dbl_lst_i_new(ft_atoi(argv[i])));
	lst_size = ft_dbl_lst_i_size(stack_a);
	i = -1;
	pivot = stack_a;
	while (++i < lst_size)
	{
		printf("Element %i: %i\n", i, pivot->content);
		pivot = pivot->next;
	}
	free_stack(stack_a);
	return (0);
}