#include "libft.h"

char	**ft_split(char const *s, char delimiter)
{
	char	**morsels;
	size_t	word_count;
	size_t	i;
	size_t	word_length;

	s = ft_strtrim(s, &delimiter);
	// if (*s == '\0')
	// 	return (ft_strdup(""));

	// contar qtas palavras tem
	word_count = count_words(s, delimiter);

	// alocar memória
	morsels = malloc(word_count * sizeof(*morsels));
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
		morsels[0] = ft_substr(s, 0, word_length);
		s += word_length;
		morsels++;
	}

	//devolver palavras
	return (morsels);
}
