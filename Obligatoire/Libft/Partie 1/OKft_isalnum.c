int	ft_isalnum(int c)
{
	if (c >= '0' && c <= '9')
		return (4);
	else if ((c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= 'a' && c <= 'z'))
		return (2);
	else
		return (0);
}
