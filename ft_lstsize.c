#include "libft.h"

int	ft_lstsize(t_list *lst)
// Parameters #1. The beginning of the list.
// Return value Length of the list.
// External functs. None
// Description Counts the number of elements in a list.
{
	int	count_items;

	count_items = 0;
	while(lst->next != NULL)
	{
		count_items++;
		lst++;
	}
	return (count_items);
}
