#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
<<<<<<< HEAD:Obligatoire/Libft/Partie 1/NOKft_memccpy.c
		if (((char *) src)[i] != c)
			((char *) dest)[i] = ((char *) src)[i];
		else
			return (dest + 1);
=======
		((char *) dest)[i] = ((char*) src)[i];
		if (((char*) src)[i] == c)
			return (dest + i + 1);
>>>>>>> main:Obligatoire/Libft/Partie 1/ft_memccpy.c
		i++;
	}
	return (NULL);
}
