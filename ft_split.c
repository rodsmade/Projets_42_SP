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

	while (*s == delimiter)
		s++;
	words = 0;
	while (ft_strchr(s, delimiter) != NULL)
	{
		words++;
		s = ft_strchr(s, delimiter);
		while (*s == delimiter)
			s++;
	}
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
	size_t	word_count;
	size_t	i;

	if (ft_strlen(s) == count_delimiters(s, c))
	{
		morsels = malloc(1 * sizeof(*morsels));
		morsels[0] = ft_strdup("");
		return (morsels);
	}
	word_count = count_words(s, c);
	morsels = malloc((word_count + 1) * sizeof(*morsels));
	if (morsels == NULL)
		return (NULL);
	i = 0;
	while (++i <= word_count)
	{
		while (s && *s == c)
			s++;
		morsels[0] = get_new_word(s, c);
		s = ft_strchr(s, c);
		morsels++;
	}
	return (morsels - word_count);
}
