#include<stdio.h>
#include<ctype.h>

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
