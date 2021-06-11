#include "libft.h"

char	*ft_strdup(const char *s)
// The  strdup() function returns a pointer to a new string which is a duplicate of the string s.  Memory for the
// new string is obtained with malloc(3), and can be freed with free(3).
{
	unsigned int	strlength;
	char 			*newstr;

	strlength = ft_strlen(s);
	newstr = ft_calloc((strlength + 1), sizeof(const char));
	if (newstr == NULL)
		return (NULL);
	// void	*ft_memcpy(void *dest, const void *src, size_t n)
	newstr = ft_memcpy(newstr, s, strlength);
	return (newstr);
}
