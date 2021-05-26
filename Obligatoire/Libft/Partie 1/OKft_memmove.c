#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
//The  memmove() function copies n bytes from memory area src to memory area dest.
// The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array
// that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.*/
// The memmove() function returns a pointer to dest.
{
	unsigned int	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *) dest)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			((char *) dest)[i - 1] = ((char *) src)[i - 1];
			i--;
		}
	}
	return (dest);
}
