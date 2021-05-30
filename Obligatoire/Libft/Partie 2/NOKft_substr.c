#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;
	unsigned int	chars_left_in_s;

	chars_left_in_s = ft_strlen(s) - start;
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

// 				start															'\0'
// 0		1		2		3		4		5		6		7		8		9		10
// start = 2;
// strlen = 10;
// len = 3;
// (strlen - start) = 8 = a partir do start termina certinho no 9. EXATAMENTE O QUE CABE. ou seje, o  '\0' de 'p' terá q ser depois disso
// se len <= (strlen - start)
// 	-> vou copiar tudo de s.
// 	-> p[length] = '\0'
// caso contrário
// 	-> p[strlen - start + 1] = '\0'