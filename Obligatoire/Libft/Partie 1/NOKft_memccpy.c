#include "libft.h"
void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((char *) src)[i] != c)
			((char *) dest)[i] = ((char *) src)[i];
		else
			return (dest + 1);
		i++;
	}
	return (NULL);
}
