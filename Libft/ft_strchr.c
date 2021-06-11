#include "libft.h"

char *ft_strchr(const char *s, int c)
//The strchr() function returns a pointer to the first occurrence of the character c in the string s.
// if not found returns NULL
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}
