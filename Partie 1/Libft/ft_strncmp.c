#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		else if(s1[i] > s2[i])
			return (1);
		i++;
	}
	if (ft_strlen(s1) == ft_strlen(s2))
		return (0);
	if (ft_strlen(s1) < ft_strlen(s2))
		return (-1);
	else
		return(1);
}

#include <stdio.h>

int	all_ok = 0;

void valida_resultado(const char *s1, const char *s2, size_t n)
{
//	if (ft_strncmp(s1, s2, n) == strncmp(s1, s2, n))
//		printf("result: OK!		s1 =%s; s2 =%s; n =%I64i.\n", s1, s2, n);

//	else
if (ft_strncmp(s1, s2, n) != strncmp(s1, s2, n))
	{
		all_ok = all_ok + 1;
		printf("Result: NOK! :(		s1 = %s; s2 = %s; n = %I64i.\n", s1, s2, n);
	}
	return;
}

int main()
{
	char		*s1 = "abcdefghij";
	char		*s2 = "abcdefghij";
	int			n = 10;

	while (n >= 0)
	{
		// s1 mesmo tamanho que e igual a s2
		s1 = "abcdefghij";
		s2 = "abcdefghij";
		valida_resultado(s1, s2, n);

		// s1 mesmo tamanho que e menor que s2
		s1 = "abcdefghij";
		s2 = "bbcdefghij";
		valida_resultado(s1, s2, n);

		// s1 mesmo tamanho que e maior que s2
		s1 = "abcdefghij";
		s2 = "aacdefghij";
		valida_resultado(s1, s2, n);

		// s1 tamanho menor que e igual a s2
		s1 = "abcde";
		s2 = "abcdefghij";
		valida_resultado(s1, s2, n);

		// s1 tamanho menor que e maior que s2
		s1 = "abcde";
		s2 = "aacdefghij";
		valida_resultado(s1, s2, n);

		// s1 tamanho menor que e menor que s2
		s1 = "abcde";
		s2 = "bbcdefghij";
		valida_resultado(s1, s2, n);

		// s1 tamanho maior que e igual que s2
		s1 = "abcdefghij";
		s2 = "abcde";
		valida_resultado(s1, s2, n);

		// s1 tamanho maior que e maior que s2
		s1 = "abcdefghij";
		s2 = "aacde";
		valida_resultado(s1, s2, n);

		// s1 tamanho maior que e menor que s2
		s1 = "abcdefghij";
		s2 = "bbcde";
		valida_resultado(s1, s2, n);

		// s1 vazio
		s1 = "";
		s2 = "abcdefghij";
		valida_resultado(s1, s2, n);

		// s2 vazio
		s1 = "abcdefghij";
		s2 = "";
		valida_resultado(s1, s2, n);

		n--;
	}

	if (all_ok == 0)
		printf("\n\n\n\n\nS U C E S S O O o 0 o 0 O 0 o O o ! ! ! ! ! 🎉🎉🎉\n");
	else
		printf("\n\n\n\n\nx_x F A I L x_x\n%i errors were found in your code!\nTry again.", all_ok);
	return (0);
}