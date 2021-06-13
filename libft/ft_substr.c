#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	chars_left_in_s;

	chars_left_in_s = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	p = malloc((len + 1) * sizeof(char));
	if (p == NULL)
	{
		free (p);
		return (NULL);
	}
	i = 0;
	while (*s && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	if (chars_left_in_s > len)
		p[len] = '\0';
	else
		p[chars_left_in_s + 1] = '\0';
	return (p);
}

