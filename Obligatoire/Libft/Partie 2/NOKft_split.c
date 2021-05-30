#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**array_of_pointers;
	int		cleft;

	array_of_pointers = malloc(2 * sizeof(char *));
	//  find delimiter point
	while (s[cleft] != c)
		cleft++;
	// joga s pro delimiter c, vai ser usado mais na frente
	s += cleft;
	// não engloba o delimiter c
	array_of_pointers[0] = malloc(cleft * sizeof(char) + 1);
	// engloba o delimiter c
	array_of_pointers[1] = malloc((ft_strlen(s) - cleft) * sizeof(char) + 1);
	array_of_pointers[0][cleft] = '\0';
	while (--cleft >= 0)
		array_of_pointers[0][cleft] = s[cleft];
	while (*s)
	{
		array_of_pointers[1][cleft] = *s;
		s++;
		cleft++;
	}
	return (array_of_pointers);
}
