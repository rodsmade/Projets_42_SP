// The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c.
// The memset() function returns a pointer to the memory area s.
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char *cptr;

	i = 0;
	cptr = (char*) s;
	while (i < n)
	{
		cptr[i] = c;
		i++;
	}
	return ((void*) cptr);
}
