#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	if (size = 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	// revisar esse retorno!!!! eh isso msm?? n devia ser chars written ou algo assim?
	// resp.: não o manual fala explicitamente q eh o size de src
	return (ft_strlen(src));
}
