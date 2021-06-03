#include "libft.h"

size_t ft_strlen(const char *s);

char	**ft_split(char const *s, char c)
{
	char	**halves;
//	char	*half0;
//	char	*half1;
	int		cleft;

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
	// ATE AQUI TA DANDO BOM PARECE, RETOMAR A PARTIR DAQUI AMANHA
	s += cleft;
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

size_t ft_strlen(const char *s)
{
	int qtd_caracteres;

	qtd_caracteres = 0;
	while (*s)
	{
		qtd_caracteres++;
		s++;
	}
	return (qtd_caracteres);
}

int main(){
	ft_split("and then the futhermost shake drove a murthering stake |in and cleft me right down to my center", '|');
	return 0;
}