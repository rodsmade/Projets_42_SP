#include "libft.h"

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
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	int				i;
	unsigned int	s1length;

	s1length = ft_strlen(s1);
	trim = malloc((s1length + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	// size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size)
	// revisar isso que tá estranho, strlcpy devolve length de s1! sempre vai dar positivo essa porra
	ft_strlcpy(trim, s1, s1length + 1);
	// começar de trás pra frente parece inteligente
	i = s1length - 1;
	while (belongs_to_set(trim[i], set))
	{
		trim[i] = '\0';
		i--;
	}
	// agora frente p trás
	while (belongs_to_set(trim[0], set))
	{
		trim = (char *) ft_memmove(trim, trim + 1, ft_strlen(trim) - 1);
		trim[ft_strlen(trim) - 1] = '\0';
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

// #include <bsd/string.h>
// #include <stdio.h>

// int main()
// {
// 	char *source1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	char *source2 = "abcdefghijklmnopqrstuvwxyz";
// 	char dest1[26];
// 	char dest2[26];
// 	size_t dest_size = 10;
	
// 	printf("resultado1 (normal)    : %li\n", strlcpy(dest1, source1, dest_size));
// 	printf("resultado2 (ft_strlcpy): %li\n", ft_strlcpy(dest2, source2, dest_size));
// 	printf("dest1: %s\n", dest1);
// 	printf("dest2: %s\n", dest2);
// 	return 0;
// }