#include "libft.h"

int		belongs_to_set(char c, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);

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
	ft_strlcpy(trim, s1, s1length);
	// começar de trás pra frente parece inteligente
	i = s1length - 1;
	while (belongs_to_set(trim[i], set))
	{
		trim[i] = '\0';
		i--;
	}
	// agora frente p trás
	i = 0;
	while (belongs_to_set(trim[0], set))
	{
		trim = (char *) ft_memmove(trim, trim + 1, ft_strlen(trim) - 1);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (*src == '\0')
		return (0);
	// TODO: testar! troquei *src por src[i]
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	// revisar esse retorno!!!! eh isso msm?? n devia ser chars written ou algo assim?
	// resp.: não o manual fala explicitamente q eh o size de src
	return (ft_strlen(src));
}

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

void	*ft_memmove(void *dest, const void *src, size_t n)
//The  memmove() function copies n bytes from memory area src to memory area dest.
// The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array
// that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.*/
// The memmove() function returns a pointer to dest.
{
	unsigned int	i;

	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *) dest)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			((char *) dest)[i - 1] = ((char *) src)[i - 1];
			i--;
		}
	}
	return (dest);
}

#include <stdio.h>
int main()
{
	char string_to_trim[100];
	char chars_to_trim_out[100];
	ft_strlcpy(string_to_trim, "aaaa adja aj kja lalalla jfdjsf a aa a a", 100);
	ft_strlcpy(chars_to_trim_out, " a", 100);
	ft_strtrim(string_to_trim, chars_to_trim_out);
//	printf("Result > '%s'\n", ft_strtrim(string_to_trim, chars_to_trim_out));
	return 0;
}