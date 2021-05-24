#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size)
{
	unsigned int	i = 0;

	if (*src == '\0')
		return (0);
	// TODO: testar! troquei *src por src[i]
	while (src[i] && i < dest_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[dest_size - 1] = '\0';
	return (ft_strlen(src));
}
