#include "libft.h"

// AREA DE FUNCOES PARA CONSEGUIR DEBUGAR
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

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*c;

	i = 0;
	c = (char*) s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
	return;
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void	*allocdmem;

	allocdmem = (void *) malloc (nmemb * size);
	if (allocdmem == NULL)
		return (NULL);
	ft_bzero(allocdmem, nmemb * size);
	return (allocdmem);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *) src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	unsigned int	strlength;
	char 			*newstr;

	strlength = ft_strlen(s);
	newstr = ft_calloc((strlength + 1), sizeof(const char));
	if (newstr == NULL)
		return (NULL);
	newstr = ft_memcpy(newstr, s, strlength);
	return (newstr);
}

char *ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

// FIM DA AREA DE FUNÇÕES PARA CONSEGUIR DEBUGAR

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
	while (*s == delimiter)
		s++;
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
		while (s && *s == c)
			s++;
		morsels++;
	}
	return (morsels - word_count);
}

#include <stdio.h>
int main()
{
	char **morsels;
	morsels = ft_split("       and   ", ' ');
	printf("%s\n", *morsels);
	return 0;
}