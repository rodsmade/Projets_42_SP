#include "libft.h"
// a string original pode ter n vezes o delimitador
// se a string tiver só ' 's e o delimitador for ' ', o retorno deve ser um ponteiro vazio (strdup("");)
// o delimitador é descartado sempre
// se todos os caracteres forem iguais ao delimitador, então retorno strdup("");
// se for "banana         abacate" e delimitador = ' '; o resultado é 2 strings: "banana" e "abacate";

// [OK] 1. função que conta qtos delimitadores tem (vai dizer qtos strings existirão no final)
static size_t	count_delimiters(char const *s, char delimiter)
{
	size_t	count;

	count = 0;
	while(*s)
	{
		if (*s == delimiter)
			count++;
		s++;
	}
	return (count);
}

// [OK] 2. conta quantas palavras (válidas) existem
static size_t	count_words(char const *s, char delimiter)
{
	size_t	words;

	words = 0;
	while(ft_strchr(s, delimiter) != NULL)
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

// 3. função que alloca e cria o array de uma palavra por vez 
static char		*get_new_word(char const *ptr, char delimiter)
{
	size_t	length;
	char	*word;

	length = 0;
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

char			**ft_split(char const *s, char c)
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
		while (*s == c)
			s++;
		morsels++;
	}
	return (morsels - word_count);
}

#include <stdio.h>
int main()
{
	char **morsels;
	morsels = ft_split("and", ' ');
	printf("%s\n", *morsels);
	return 0;
}