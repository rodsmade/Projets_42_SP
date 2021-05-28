int	ft_isprint(int c)
{
	if (c == ' ')
		return (64);
	else if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64)
		|| (c >= 91 && c <= 96) || (c >= 123 && c <= 126))
		return (16);
	else if (c >= '0' && c <= '9')
		return (4);
	else if ((c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= 'a' && c <= 'z'))
		return (2);
	else
		return (0);
}
