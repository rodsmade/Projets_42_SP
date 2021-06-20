#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
// Parameters #1. The adress of a pointer to an element.
// #2. The adress of the function used to delete the
// content of the element.
// Return value None
// External functs. free
// Description Deletes and frees the given element and every
// successor of that element, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.
{
	t_list	**temp;

	while (*lst)
	{
		temp = lst;
		ft_lstdelone(*lst, del);
		lst = temp;
	}
	lst = NULL;
}