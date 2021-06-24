#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	f(lst->content);
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
}
