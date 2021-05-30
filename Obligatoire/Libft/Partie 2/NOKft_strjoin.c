#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		i;

	joint = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (joint == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		joint[i] = s1[i];
	i = -1;
	while (s2[++i])
		joint[i + ft_strlen(s1)] = s2[i];
	joint[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (joint);
}
