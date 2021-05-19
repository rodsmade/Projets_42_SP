#include<libft.h>

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