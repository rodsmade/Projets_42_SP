/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:50:53 by roaraujo          #+#    #+#             */
/*   Updated: 2021/12/29 14:59:10 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(const char *s, char delimiter)
{
	size_t	words;

	words = 0;
	if (*s == '\0')
		return (words);
	if (delimiter == '\0')
		return (1);
	while (*s == delimiter && *s)
		s++;
	while (*s)
	{
		words++;
		while (*s != delimiter && *s)
			s++;
		while (*s == delimiter && *s)
			s++;
	}
	return (words);
}

static void	*rollback(char **morsels)
{
	while (*morsels)
		free(*morsels);
	free(morsels);
	return (NULL);
}

static char	**write_words(char **morsels, const char *s, char delimiter)
{
	size_t	length;
	size_t	i;

	i = 0;
	while (*s)
	{
		length = 0;
		while (s[length] != delimiter && s[length])
			length++;
		morsels[i] = (char *) malloc(length * sizeof(char) + 1);
		if (morsels[i] == NULL)
			return (rollback(morsels));
		morsels[i][length] = '\0';
		while (length > 0)
		{
			morsels[i][length - 1] = s[length - 1];
			length--;
		}
		while (*s != delimiter && *s)
			s++;
		while (*s == delimiter && *s)
			s++;
		i++;
	}
	return (morsels);
}

char	**ft_split(char const *s, char delimiter)
{
	char	**morsels;
	size_t	words;

	words = count_words(s, delimiter);
	morsels = (char **) malloc((words + 1) * sizeof(char *));
	if (morsels == NULL)
		return (NULL);
	while (*s == delimiter && *s)
		s++;
	morsels = write_words(morsels, s, delimiter);
	morsels[words] = NULL;
	return (morsels);
}
