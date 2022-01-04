#include "pipex.h"

int main()
{
	char a[] = "   aaaateste   oxeaaa     ";
	printf("orig: >>%s<<\n", a);
	printf("trim: >>%s<<\n", ft_strtrim(a, " "));
}