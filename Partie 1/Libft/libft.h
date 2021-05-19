#ifndef LIBFT_H
# define LIBFT_H

# include<stddef.h> 

int ft_atoi(const char *nptr);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
size_t ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strnstr(const char	*big, const char *little, size_t len);
int ft_tolower(int c);
int ft_toupper(int c);

#endif 