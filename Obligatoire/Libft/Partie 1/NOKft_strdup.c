#include "libft.h"

char	*ft_strdup(const char *s)
// The  strdup() function returns a pointer to a new string which is a duplicate of the string s.  Memory for the
// new string is obtained with malloc(3), and can be freed with free(3).
{
	unsigned int	strlength;
	char 			*newstr;

	strlength = ft_strlen(s);
	newstr = malloc ((strlength + 1) * sizeof(const char));
	return (newstr);
}
