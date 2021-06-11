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
#include <bsd/string.h>

int	all_ok = 0;
int	total_runs = 0;

void valida_resultado(const char *s1, const char *s2, size_t n)
{
//	if (ft_strncmp(s1, s2, n) == strncmp(s1, s2, n))
//		printf("result: OK!		s1 =%s; s2 =%s; n =%I64i.\n", s1, s2, n);

//	else
	total_runs++;
	if (ft_strncmp(s1, s2, n) != strncmp(s1, s2, n))
	{
		all_ok = all_ok + 1;
		printf("Result: NOK! :(		s1 = %s; s2 = %s; n = %I64li.\n", s1, s2, n);
	}
	return;
}