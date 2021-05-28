#include "libft.h"
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	int				j;

	i = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (*haystack && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && *needle)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *) &(haystack[i - ft_strlen(needle)]));
			else if (needle[j] != haystack[i] || haystack[i] == '\0')
				break ;
		}
		i++;
	}
	return (NULL);
}
