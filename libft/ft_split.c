#include "libft.h"

static size_t	count_delimiters(char const *s, char delimiter)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == delimiter)
			count++;
		s++;
	}
	return (count);
}

static size_t	count_words(char const *s, char delimiter)
{
	size_t	words;

	words = 0;
	while (*s == delimiter)
		s++;
	while (ft_strchr(s, delimiter) != NULL)
	{
		words++;
		s = ft_strchr(s, delimiter);
		while (*s == delimiter)
			s++;
	}
	if (*s != delimiter && *s)
		words++;
	return (words);
}

static char	*get_new_word(char const *ptr, char delimiter)
{
	size_t	length;
	char	*word;

	length = 0;
	while (*ptr == delimiter)
		ptr++;
	while (ptr[length] != delimiter && ptr[length])
		length++;
	word = ft_calloc(length + 1, sizeof(char));
	if (word == NULL)
		return (NULL);
	word[length] = '\0';
	while (length > 0)
	{
		word[length - 1] = ptr[length - 1];
		length--;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**morsels;
	size_t	slength;
	size_t	delim_count;
	size_t	word_count;
	size_t	i;

	slength = ft_strlen(s);
	delim_count = count_delimiters(s, c);
	word_count = count_words(s, c);
	if (word_count == 0 || slength == delim_count)
		return (NULL);
	morsels = malloc((word_count + 1) * sizeof(*morsels));
	if (morsels == NULL)
		return (NULL);
	i = 0;
	while (++i <= word_count)
	{
		morsels[0] = get_new_word(s, c);
		s = ft_strchr(s, c);
		while (s && *s == c)
			s++;
		morsels++;
	}
	return (morsels - word_count);
}
