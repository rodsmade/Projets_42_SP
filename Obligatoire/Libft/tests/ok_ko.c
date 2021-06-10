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

// STRLCPY
// OBS: COMPILAR COM -lbsd: "compila ft_strlcpy.c OKft_strlen.c -lbsd"
// OBS: COMPILAR COM ft_strlen.c

#include <bsd/string.h>
#include <stdio.h>

int main()
{
	char *source1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *source2 = "abcdefghijklmnopqrstuvwxyz";
	char dest1[26];
	char dest2[26];
	size_t dest_size = 229;
	
	printf("resultado1 (normal)    : %li\n", strlcpy(dest1, source1, dest_size));
	printf("resultado2 (ft_strlcpy): %li\n", ft_strlcpy(dest2, source2, dest_size));
	printf("dest1: %s\n", dest1);
	printf("dest2: %s\n", dest2);
	return 0;
}

// STRLCAT
// OBS: COMPILAR COM -lbsd: "compila ft_strlcpy.c OKft_strlen.c -lbsd"
// OBS: COMPILAR COM ft_strlen.c
// TABELINHA VERDADE HANDY AF:
// Before :                || After :
// dst   | src   | size    || dst      | return
// ------------------------||--------------------
// dst\0 | src\0 | 0       || dst\0    | 3
// dst\0 | src\0 | 1       || dst\0    | 4
// dst\0 | src\0 | 2       || dst\0    | 5
// dst\0 | src\0 | 3       || dst\0    | 6
// dst\0 | src\0 | 4       || dst\0    | 6
// dst\0 | src\0 | 5       || dsts\0   | 6
// dst\0 | src\0 | 6       || dstsr\0  | 6
// dst\0 | src\0 | 7       || dstsrc\0 | 6
// dst\0 | src\0 | 8       || dstsrc\0 | 6

// (SU)BZERO

#include<stdio.h>
#include<string.h>

int main()
{
	// ATENCAO NUNCA MAIS DECLARAR STRING COMO CHAR *S = "LALALA" PQ ASSIM DA RUIM CARAI
	char str[90];
	char *s = strcpy(str, "AAAAAAAA");
	printf("s antes: %s\n", s);
	ft_bzero(s, 5);
	printf("s despues: %s\n", s);
	return 0;
}

// MEMSET
#include<stdio.h>
#include<string.h>

int main()
{
	int n = 0;
	// ATENCAO NUNCA MAIS DECLARAR STRING COMO CHAR *S = "LALALA" PQ ASSIM DA RUIM CARAI
	char str[90];
	while(n < 6)
	{
		char *s = strcpy(str, "AAAAAAAA");
		printf("n = %i\n", n);
		printf("s antes: %s, n = %i\n", s, n);
		ft_memset(s, 'c', n);
		printf("s despues: %s\n", s);
		n++;
	}
	return 0;
}

// STRCHR

#include<string.h>
#include<stdio.h>
int main()
{
	char pool[200];
	char *haystack = strcpy(pool, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	if (ft_strchr(haystack, ' ') == strchr(haystack, ' '))
		printf("OK! :)\n");
	else
		printf("NOK! :(\n");
	return 0;
}

// STRRCHAR

#include<string.h>
#include<stdio.h>
int main()
{
	char pool[200];
	char *haystack = strcpy(pool, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	if (ft_strrchr(haystack, 'a') == strrchr(haystack, 'a'))
		printf("OK! :)\n");
	else
		printf("NOK! :(\n");
	return 0;
}

// MEMCHR

#include<string.h>
#include<stdio.h>
int main()
{
	char pool[200];
	char *haystack = strcpy(pool, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	unsigned int n = 26;

	if (ft_memchr(haystack, 'A', n) == memchr(haystack, 'A', n))
		printf("OK! :)\n");
	else
		printf("NOK! :(\n");
	return 0;
}

// STRCMP

#include<string.h>
#include<stdio.h>

int main()
{
	char pool[200];
	char pool2[200];
	char *this = strcpy(pool, "aaaaCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	char *that = strcpy(pool2, " ABCDEq   FGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	unsigned int n = 26;

	if (ft_memcmp(this, that, n) == memcmp(that, this, n))
	{
		printf("OK! :)\n");
		printf("ft : %i\n", ft_memcmp(this, that, n));
		printf("mem: %i\n", memcmp(that, this, n));
	}
	else
	{
		printf("NOK! :(\n");
		printf("ft : %i\n", ft_memcmp(this, that, n));
		printf("mem: %i\n", memcmp(that, this, n));
	}
}

// MEMMOVE e MEMCPY

#include <stdio.h>
#include <string.h>
void print_elements(char *array, int size)
{
  int i;
  printf ("Elements : ");
  for (i = 0; i < size; i++) {
    printf ("%c, ", array[i]);
  }
  printf ("\n");
}
int main()
{
// works fine:
  printf("Works fine:\n");
  char c_array[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  print_elements(c_array, sizeof(c_array));
  printf("After memcpy()\n");
  ft_memcpy((void *)&c_array[1], (void *)&c_array[3], 5);
  print_elements(c_array, sizeof(c_array));
// doesn't work well
  printf("Doesn't work fine:\n");
  char c_array2[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  print_elements(c_array2, sizeof(c_array2));
  printf("After memcpy()\n");
  ft_memcpy((void *)&c_array2[5], (void *)&c_array2[3], 5);
  print_elements(c_array2, sizeof(c_array2));
// doesn't work well
  printf("Works fine:\n");
  char c_array3[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  print_elements(c_array3, sizeof(c_array3));
  printf("After memmove()\n");
  memmove((void *)&c_array3[5], (void *)&c_array3[3], 5);
  print_elements(c_array3, sizeof(c_array3));
}

// MEMCCPY
#include <stdio.h>
#include <string.h>
int main()
{
	char result[100];
	char *s = strcpy(result, "01234567890123456789");
	printf("retorno: %s\n", (char *) ft_memccpy(s, "camiseta", 'e', 8));
	printf("dest: %s\n", s);
	return 0;
}

// STRDUP

#include <stdio.h>
#include <string.h>
int main()
{
	char pool[200];
	char *original;
	char *copia;

	original = strcpy(pool, "pamonhaaaaa");
	copia = ft_strdup(original);
	printf("Original: %s\n", original);
	printf("Copia: %s\n", copia);
	ft_bzero(original, ft_strlen(original));
	printf("Original: %s\n", original);
	printf("Copia: %s\n", copia);
	return(0);
}

// SPLIT

#include <stdio.h>
int main(){
	char	**retorno;
	char	*split_this = "and then the futhermost shake drove a murthering stake |in and cleft me right down to my center";
	char	delimiter = '|';
	retorno = ft_split(split_this, delimiter);
	printf("Delimiter: '%c'\n", delimiter);
	printf("retorno 0: '%s'\n", retorno[0]);
	printf("retorno 1: '%s'\n", retorno[1]);
	return 0;
}

// STRJOIN

#include <stdio.h>
int main()
{
	char *string1 = "And then the furthermost shake drove a murthering stake in ";
	char *string2 = "and cleft me right down through my center";
	char *string3 = ".\nAnd i shouldn't say so, but i know that it was then and never.";
	printf("Resultado > %s\n", ft_strjoin(ft_strjoin(string1, string2), string3));
	return 0;
}