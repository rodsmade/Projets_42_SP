#include "libft.h"

int	ft_lstsize(t_list *lst)
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
