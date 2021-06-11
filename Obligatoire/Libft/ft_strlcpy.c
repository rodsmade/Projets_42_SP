#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (*src == '\0')
		return (0);
	// TODO: testar! troquei *src por src[i]
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	// revisar esse retorno!!!! eh isso msm?? n devia ser chars written ou algo assim?
	// resp.: não o manual fala explicitamente q eh o size de src
	return (ft_strlen(src));
}
