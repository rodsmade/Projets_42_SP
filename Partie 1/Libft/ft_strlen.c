int	ft_strlen(char *str)
{
	int qtd_caracteres;

	qtd_caracteres = 0;
	while (*str)
	{
		qtd_caracteres++;
		str++;
	}
	return (qtd_caracteres);
}
