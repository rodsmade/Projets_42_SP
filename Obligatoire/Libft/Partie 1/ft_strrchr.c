#include "libft.h"

char	*ft_strrchr(const char *s, int c)
// The strrchr() function returns a pointer to the last occurrence of the character c in the string s.
// if not found returns NULL
{
	int length;

	length = ft_strlen(s);
	while (--length >= 0)
	{
		if (s[length] == c)
			return ((char *) s + length);
	}
	return (NULL);
}
