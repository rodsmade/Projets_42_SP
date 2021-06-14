#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	length;
	char	*result;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	result = malloc((length + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[length] = '\0';
	while (length > 0)
	{
		result[length - 1] = f(length - 1, s[length - 1]);
		length--;
	}
	return (result);
}
