#include "../libft.h"

int		belongs_to_set(char c, char const *set);

// trail o thought:
// 1. allocates mem
// 2. trims (reposiciona tudo)
//		usar ft_memmove
//	void	*ft_memmove(void *dest, dest + 1, length dest + 1)
//	The  memmove() function copies n bytes from memory area src to memory area dest.
// 3. string front to back while (belongs to set)
//	trims.
// 4. string back to front while (belongs to set)
// 5. return s1;
char	*ft_strtr(char const *s1, char const *set)
{
	char			*trim;
	int				i;
	unsigned int	s1length;

	s1length = ft_strlen(s1);
	trim = malloc((s1length + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	// size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size)
	if (ft_strlcpy(trim, s1, s1length) != s1length)
		return (NULL);
	// começar de trás pra frente parece inteligente
	i = ft_strlen(trim) - 1;
	while (belongs_to_set(trim[i], set))
	{
		trim[i] = '\0';
		i--;
	}
	// agora frente p trás
	i = 0;
	while (belongs_to_set(trim[i], set))
	{
		trim = (char *) ft_memmove(trim + i, trim + i + 1, ft_strlen(trim) - 1);
		i++;
	}
	return (trim);
}

// 1. belongs to set
int	belongs_to_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

#include <stdio.h>
int main()
{
	char *string_to_trim = "aaaa adja aj kja lalalla jfdjsf a aa a a";
	char *chars_to_trim_out = "a ";
	printf("Result > %s\n", ft_strtr(string_to_trim, chars_to_trim_out));
	return 0;
}