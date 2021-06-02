#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**halves;
	int		cleft;

	halves = malloc(2 * sizeof(char *));
	//  find delimiter point
	while (s[cleft] != c)
		cleft++;
	// joga s pro delimiter c, vai ser usado mais na frente
	s += cleft;
	// não engloba o delimiter c
	halves[0] = malloc(cleft * sizeof(char) + 1);
	// engloba o delimiter c
	halves[1] = malloc((ft_strlen(s) - cleft) * sizeof(char) + 1);
	if (halves == NULL || halves[0] == NULL || halves[1] == NULL)
		return (NULL);
	halves[0][cleft] = '\0';
	while (--cleft >= 0)
		halves[0][cleft] = s[cleft];
	while (*s)
	{
		halves[1][cleft] = *s;
		s++;
		cleft++;
		if (*(s + 1) == '\0')
			halves[1][cleft + 1] = '\0';
	}
	return (halves);
}
