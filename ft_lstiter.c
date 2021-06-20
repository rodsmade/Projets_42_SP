#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
// Parameters #1. The adress of a pointer to an element.
// #2. The adress of the function used to iterate on
// the list.
// Return value None
// External functs. None
// Description Iterates the list ’lst’ and applies the function
// ’f’ to the content of each element.
{
	if (lst == NULL)
		return;
	f(lst->content);
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
}
