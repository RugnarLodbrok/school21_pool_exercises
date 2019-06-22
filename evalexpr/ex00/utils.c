int is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void skip_spaces(char **str)
{
	while (**str && is_space(**str))
		(*str)++;
}

void skip_non_spaces(char **str)
{
	while (**str && !is_space(**str))
		(*str)++;
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	int				ended;

	len = 0;
	ended = 0;
	while (size > 1)
	{
		size--;
		*dest = *src;
		if (!*src)
		{
			ended = 1;
			break ;
		}
		dest++;
		src++;
		len++;
	}
	if (size && !ended)
		*dest = 0;
	while (*(src++))
		len++;
	return (len);
}
