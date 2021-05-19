int ft_isalnum(int c)
{
	if  (c >= '0' && c <= '9')
		return (4);
	else if ((c >= 'A' && c <= 'Z'))
			return (1);
	else if ((c >= 'a' && c <= 'z'))
			return (2);
	else
		return (0);
}

#include<stdio.h>
#include<ctype.h>

int main()
{
	for (int i = 0; i < 256; i++)
	{
		printf("i = %d: ", i);
		if (isalnum(i) == ft_isalnum(i))
			printf("OK!\n");
		else
			printf("KO! :(\n");
	}
	return 0;
}
