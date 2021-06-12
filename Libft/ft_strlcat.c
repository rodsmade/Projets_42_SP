#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	// o manual é MUITO confuso e só consegui entender olhando o código fonte do projeto de open source da apple
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = 0;
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	i = 0;
	if (dstlen < size)
	{
		while ((i + dstlen) < (size - 1) && src[i])
		{
			dst[i + dstlen] = src[i];
			i++;
		}
		dst[i + dstlen] = '\0';
	}
	return (dstlen + srclen);
}

#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char destcat[] = "largatixa";
	char srccat[] = "malasiatica";
	char destcat1[] = "largatixa";
	char srccat1[] = "malasiatica";
	printf("dest: %ld   src: %ld\n", ft_strlen(destcat), ft_strlen(srccat));
	int retorno = ft_strlcat(destcat, srccat, 1);
	int retorno1 = strlcat(destcat1, srccat1, 1);


	

	printf("dest: %s ... retorno: %d\n", destcat, retorno);
	printf("final: %ld\n", ft_strlen(destcat));

	printf(" OOOOP dest: %s ... retorno: %d\n", destcat1, retorno1);
	printf("O OO OO Ofinal: %ld\n", ft_strlen(destcat1));
	return (0);
}