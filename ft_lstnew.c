#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newitem;

	newitem = malloc(sizeof(t_list));
	newitem->content = content;
	newitem->next = NULL;
	return (newitem);
}
