#include <stdlib.h>

static long int    ft_recursive_power(int nb, int power);
static char    *ft_left_trim(char const *s1, char const c);
size_t ft_strlen(const char *s);
void    *ft_memmove(void *dest, const void *src, size_t n);
size_t    ft_strlcpy(char *dst, const char *src, size_t dest_size);
char    *ft_strjoin(char const *s1, char const *s2);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

char    *ft_itoa(int n)
{
    char        *result;
    long int    big_n;
    int            needle;

	big_n = n;
    if (n < 0)
        big_n *= -1;

    // 10 dígitos + 1 sinal + '\0'
    result = malloc(11 * sizeof(char) + 1);
    if (result == NULL)
        return (NULL);
    // tratar quando n = 0 pqp
	if (n == 0)
		return ("0");

    needle = 0;
    while (needle < 10 || big_n > 0)
    {
        // 2147483647
        result[needle] = (big_n / ft_recursive_power(10, (9 - needle))) + '0';
        big_n = big_n - (result[needle] - '0') * ft_recursive_power(10, (9 - needle));
        needle++;
    }

    result[10] = '\0';
    result = ft_left_trim(result, '0');

    if (n < 0)
        result = ft_strjoin("-", result);

    return result;
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

static long int    ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    else
        return (nb * ft_recursive_power(nb, power - 1));
}

static char    *ft_left_trim(char const *s1, char const c)
{
    char    *trim;
    int        i;
    int   length;

    length = ft_strlen(s1);
    trim = malloc((ft_strlen(s1) + 1) * sizeof(char));
    if (trim == NULL)
        return (NULL);
    // size_t    ft_strlcpy(char *dst, const char *src, size_t dest_size)
    if (ft_strlcpy(trim, s1, length) != length)
        return (NULL);
    i = 0;
    while (trim[0] == c)
    {
        trim = (char *) ft_memmove(trim, trim + 1, ft_strlen(trim) - 1);
		trim[length - 1 - i] = '\0';
        i++;
    }
    return (trim);
}

void    *ft_memmove(void *dest, const void *src, size_t n)
//The  memmove() function copies n bytes from memory area src to memory area dest.
// The memory areas may overlap: copying takes place as though the bytes in src are first copied into a temporary array
// that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.*/
// The memmove() function returns a pointer to dest.
{
    unsigned int    i;

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

size_t    ft_strlcpy(char *dst, const char *src, size_t dest_size)
{
    unsigned int    i;
    unsigned int    chars_written;

    i = 0;
    chars_written = 0;
    if (*src == '\0')
        return (0);
    // TODO: testar! troquei *src por src[i]
    while (src[i] && i < dest_size)
    {
        dst[i] = src[i];
        chars_written++;
        i++;
    }
    dst[chars_written] = '\0';
    return (ft_strlen(src));
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *joint;
    int        i;

    joint = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (joint == NULL)
        return (NULL);
    i = -1;
    while (s1[++i])
        joint[i] = s1[i];
    i = -1;
    while (s2[++i])
        joint[i + ft_strlen(s1)] = s2[i];
    joint[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    return (joint);
}

void	ft_putnbr_fd(int n, int fd)
{
	// vai precisar da itoa
	// joga resultado itoa em ft_putstr_fd
	ft_putstr_fd(ft_itoa(n), fd);
}

#include <unistd.h>
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

#include <stdio.h>
int main()
{
	ft_putnbr_fd(-120, 1);
	return (0);
}
