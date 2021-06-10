#include "libft.h"
<<<<<<< HEAD:Obligatoire/Libft/Partie 1/ft_strlcpy.c
=======

size_t ft_strlen(const char *s);

>>>>>>> main:Obligatoire/Libft/Partie 1/OKft_strlcpy.c
size_t	ft_strlcpy(char *dst, const char *src, size_t dest_size)
{
	unsigned int	i;
	unsigned int	chars_written;

	i = 0;
	chars_written = 0;
	if (*src == '\0')
		return (0);
	while (src[i] && i < dest_size - 1)
	{
		dst[i] = src[i];
		chars_written++;
		i++;
	}
	dst[chars_written] = '\0';
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


int main()
{
	char *trim;
	trim = malloc(11);

	ft_strlcpy(trim, "0000000002", 10);
	return 0;
}