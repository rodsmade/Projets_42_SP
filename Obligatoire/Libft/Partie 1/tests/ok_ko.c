#include<stdio.h>
#include<ctype.h>

// IS _____STH______
int main()
{
	int iterations = 256;
	int all_ok = 0;
	for (int i = 0; i < iterations; i++)
	{
		printf("i = %d: ", i);
		if (isdigit(i) == ft_isdigit(i))
		{
			printf("OK!\n");
			all_ok++;
		}
		else
			printf("KO! :(\n");
	}
	printf("\n\n-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_**\n");
	printf("_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_*-*_\n\n");
	if (all_ok == iterations)
		printf("ALL OK ! ! ! Way to go.\n");
	else
		printf("Capotou ): see log above. %d\n", all_ok);
	return 0;
}

// TO UPPER / LOWER
#include<stdio.h>

int main()
{
	printf("A -> %c\n", ft_tolower('A'));
	printf("B -> %c\n", ft_tolower('B'));
	printf("C -> %c\n", ft_tolower('C'));
	printf("Z -> %c\n", ft_tolower('Z'));
	printf("a -> %c\n", ft_tolower('a'));
	printf("b -> %c\n", ft_tolower('b'));
	printf("c -> %c\n", ft_tolower('c'));
	printf("z -> %c\n", ft_tolower('z'));
	printf("  -> %c\n", ft_tolower(' '));
	printf("@ -> %c\n", ft_tolower('@'));
	printf("* -> %c\n", ft_tolower('*'));
	return 0;
}

// FT_STRLEN

#include<stdio.h>
int main()
{
	char *stringe = "Qtos chars tem esse string";
	if (strlen(stringe) == ft_strlen(stringe))
		printf("YIS");
	else
		printf("YIKES");
	return 0;
}

// ATOI

#include<stdlib.h>
#include<stdio.h>
int main()
{
	char *p = " 	2147483647 a a a ";
	printf("String: %s:\n", p);
	printf("atoi:         %i\n", atoi(p));
	printf("ft_atoi:      %i\n", ft_atoi(p));
	return (0);
}

// STRNSTR

#include <stdio.h>

int main(void)
{
	char *haystack = "minha haystack ahahaha mimos";
	char *needle = "ack";
	int length = 2;

	printf("Resultado:	%s\n", ft_strnstr(haystack, needle, length));
	return (0);
}

