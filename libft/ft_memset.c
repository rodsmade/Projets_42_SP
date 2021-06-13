#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*cptr;

	i = 0;
	cptr = (char *) s;
	while (i < n)
	{
		cptr[i] = c;
		i++;
	}
	return ((void *) cptr);
}
