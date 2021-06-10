#include "libft.h"

size_t ft_strlen(const char *s);

char	**ft_split(char const *s, char c)
{
	char	**halves;
//	char	*half0;
//	char	*half1;
	int		cleft;
	int		i;

	halves = malloc(2 * sizeof(*halves));
	//  find delimiter point
	cleft = 0;
	while (s[cleft] != c)
		cleft++;
	// não engloba o delimiter c
//	half0 = malloc(cleft * sizeof(char) + 1);
	halves[0] = malloc(cleft * sizeof(char) + 1);
	// engloba o delimiter c
//	half1 = malloc((ft_strlen(s) - cleft) * sizeof(char) + 1);
	halves[1] = malloc((ft_strlen(s) - cleft) * sizeof(char) + 1);
	if (halves[0] == NULL || halves[1] == NULL)
		return (NULL);
	halves[0][cleft] = '\0';
	halves[1][ft_strlen(s) - cleft] = '\0';
	// ATE AQUI TA DANDO BOM PARECE, RETOMAR A PARTIR DAQUI AMANHA
	i = 0;
	while (s[i])
	{
		if (i < cleft)
			// não inclui o delimiter c
			halves[0][i] = s[i];
		else
			halves[1][i - cleft] = s[i];
		i++;
	}
	return (halves);
}
