#include "libft.h"

static int	count_words(const char *s, char delimiter)
{
	size_t	word_count;

	if (*s == '\0')
		return (0);
	word_count = 1;
	while((s = ft_strchr(s, delimiter)) && *s)
	{
		while (*s == delimiter)
			s++;
		word_count++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char delimiter)
// percorrer tudo uma vez só
// usar 2 mallocs
// ñ usar funções da libft pq vai dar ruim de leakage
// criar função "free_all" pra ir liberando alocações se der ruim no meio do caminho, rollbackzão
{
	char	**morsels;
	size_t	i;
	size_t	word_count;
	size_t	word_length;

	s = ft_strtrim(s, &delimiter);
	// if (*s == '\0')
	// 	return (ft_strdup(""));

	// contar qtas palavras tem
	word_count = count_words(s, delimiter);

	// alocar memória
	morsels = malloc((word_count + 1) * sizeof(*morsels));
	if (morsels == NULL)
		return (NULL);

	// montar palavras
	i = 0;
	while(++i <= word_count)
	{
		while (*s && *s == delimiter)
			s++;
		word_length = 0;
		while(s[word_length] != delimiter && s[word_length])
			word_length++;
		morsels[i - 1] = ft_substr(s, 0, word_length);
		// rollbackzão caso dê errado
		if (morsels[i - 1] == NULL)
			return (NULL);
		s += word_length;
	}

	//devolver palavras
	morsels[word_count] = NULL;
	return (morsels);
}
