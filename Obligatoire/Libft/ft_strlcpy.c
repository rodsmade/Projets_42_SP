#include "libft.h"

size_t ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size)
{
	unsigned int	i;
	unsigned int	chars_written;

	i = 0;
	chars_written = 0;
	if (*src == '\0')
		return (0);
	// TODO: testar! troquei *src por src[i]
	while (src[i] && i < dest_size - 1)
	
	{
		dst[i] = src[i];
		chars_written++;
		i++;
	}
	dst[chars_written] = '\0';
	// revisar esse retorno!!!! eh isso msm?? n devia ser chars written ou algo assim?
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


#include <stdio.h>
int main()
{
	char dest[100];
	char *source = "abcde";
	int size = 10;
	ft_strlcpy(dest,source,size);
	printf("dest > '%s'\n", dest);
	return 0;
}