int	ft_isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= 'a' && c <= 'z'))
		return (2);
	else
		return (0);
}
