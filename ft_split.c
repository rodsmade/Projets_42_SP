#include "libft.h"

// static int	words(const char *s, char delimiter)
// {
// 	size_t	words;

// 	if (*s == '\0')
// 		return (0);
// 	words = 1;
// 	while((s = ft_strchr(s, delimiter)) && *s)
// 	{
// 		while (*s == delimiter)
// 			s++;
// 		words++;
// 	}
// 	return (words);
// }

// char	**ft_split(char const *s, char delimiter)
// // percorrer tudo uma vez só
// // usar 2 mallocs
// // ñ usar funções da libft pq vai dar ruim de leakage
// // criar função "free_all" pra ir liberando alocações se der ruim no meio do caminho, rollbackzão
// {
// 	char	**morsels;
// 	size_t	i;
// 	size_t	words;
// 	size_t	length;

// 	s = ft_strtrim(s, &delimiter);

// 	// contar qtas palavras tem
// 	words = words(s, delimiter);

// 	// alocar memória
// 	morsels = malloc((words + 1) * sizeof(*morsels));
// 	if (morsels == NULL)
// 		return (NULL);

// 	// montar palavras
// 	i = 0;
// 	while(++i <= words)
// 	{
// 		while (*s && *s == delimiter)
// 			s++;
// 		length = 0;
// 		while(s[length] != delimiter && s[length])
// 			length++;
// 		morsels[i - 1] = ft_substr(s, 0, length);
// 		// rollbackzão caso dê errado
// 		if (morsels[i - 1] == NULL)
// 			return (NULL);
// 		s += length;
// 	}

// 	//devolver palavras
// 	morsels[words] = NULL;
// 	return (morsels);
// }

static int	count_words(const char *s, char delimiter)
{
	size_t	words;

// delimiter eh \0
// s tá vazio - ok, wc = 0
// s só tem delimiters - ok, wc = 0;
	words = 0;
	if (*s == '\0' || delimiter == '\0')
		return (words);
	while(*s == delimiter)
		s++;
	while(*s)
	{
		words++;
		while (*s != delimiter)
			s++;
		while (*s == delimiter)
			s++;
	}
	return (words);
}

void	*rollback(char **morsels)
{
	while (*morsels)
		free(*morsels);
	free(morsels);
	return (NULL);
}

char	**ft_split(char const *s, char delimiter)
{
	char	**morsels;
	size_t	words;
	size_t	length;
	size_t	i;

	words = count_words(s, delimiter);
	morsels = malloc((words + 1) * sizeof(*morsels));
	while (*s == delimiter)
			s++;
	i = 0;
	while (*s)
	{
		// encontrar o tamanho da palavra
		length = 0;
		while (s[length] != delimiter && s[length])
			length++;
		// montar palavra
		morsels[i] = malloc(length * sizeof(char) + 1);
		if (morsels[i] == NULL)
			return (rollback(morsels));
		morsels[i][length] = '\0';
		while (length > 0)
		{
			morsels[i][length - 1] = s[length - 1];
			length--;
		}
		while (*s != delimiter)
			s++;
		while (*s == delimiter)
			s++;
		i++;
	}
	morsels[words] = NULL;
	return (morsels);
}

// #include<stdio.h>
// int main()
// {
// 	int a;
// 	a = count_words("        and then the furthermost shake drove a murthering stake in and       ", ' ');
// 	// printf("COUNT> %i\n", a);
// 	// a = count_words("        and       ", ' ');
// 	// printf("COUNT> %i\n", a);
// 	// a = count_words("        and", ' ');
// 	// printf("COUNT> %i\n", a);
// 	// a = count_words("and       ", ' ');
// 	// printf("COUNT> %i\n", a);
// 	// a = count_words("and", ' ');
// 	// printf("COUNT> %i\n", a);
// 	// a = count_words("        and then the furthermost shake drove a murthering stake in and       ", '\0');
// 	// printf("COUNT> %i\n", a);
// 	// a = count_words("           ", ' ');
// 	// printf("COUNT> %i\n", a);
// 	// a = count_words("", ' ');
// 	// printf("COUNT> %i\n", a);
// 	char **morsels;
// 	morsels = ft_split("        and then the furthermost shake drove a murthering stake in and       ", ' ');
// 	int i = -1;
// 	while(++i < a)
// 		printf("palavra %i>\t%s\n", i, morsels[i]);
// 	return 0;
// }