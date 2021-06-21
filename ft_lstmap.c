#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// Parameters #1. The adress of a pointer to an element.
// #2. The adress of the function used to iterate on
// the list.
// #3. The adress of the function used to delete the
// content of an element if needed.
// Return value The new list. NULL if the allocation fails.
// External functs. malloc, free
// Description Iterates the list ’lst’ and applies the function
// ’f’ to the content of each element. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of an element if needed
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (lst == NULL)
		return (NULL);
	new_elem = ft_lstnew((*f)(lst->content));
	if (new_elem == NULL)
	{
		free(new_elem);
		return (NULL);
	}
	new_lst = new_elem;
	lst = lst->next;
	while (lst)
	{
		new_elem->next = ft_lstnew((*f)(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_elem = new_elem->next;
		lst = lst->next;
	}
	return (new_lst);
}
