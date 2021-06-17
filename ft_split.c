#include "libft.h"

static int	count_words(const char *s, char delimiter)
{
	size_t	word_count;

	word_count = 1;
	while((s = ft_strchr(s, delimiter)))
	{
		while (*s == delimiter)
			s++;
		word_count++;
	}
	return (word_count);
}

// static char	*get_new_word(char const *ptr, char delimiter)
// {
// 	size_t	length;
// 	char	*word;

// 	length = 0;
// 	while (*ptr == delimiter)
// 		ptr++;
// 	while (ptr[length] != delimiter && ptr[length])
// 		length++;
// 	word = ft_calloc(length + 1, sizeof(char));
// 	if (word == NULL)
// 		return (NULL);
// 	word[length] = '\0';
// 	while (length > 0)
// 	{
// 		word[length - 1] = ptr[length - 1];
// 		length--;
// 	}
// 	return (word);
// }

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
		morsels[0] = ft_substr(s, 0, word_length);
		s += word_length;
		morsels++;
	}

	//devolver palavras
	morsels = 0;
	return (morsels - word_count);
}
