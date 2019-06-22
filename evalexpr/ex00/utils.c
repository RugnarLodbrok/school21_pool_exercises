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

int	ft_strcmp(char *s1, char *s2)
{
	while (1)
	{
		if (*s1 - *s2)
			return (*s1 - *s2);
		if (!(*s1 && *s2))
			break ;
		s1++;
		s2++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int n;
	
	n = 0;
	while (*str++)
		n++;
	return (n);
}

int	ft_atoi(char *str)
{
	int v;
	int is_positive;

	v = 0;
	is_positive = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		is_positive = -1;
		if (*str == '+')
			is_positive = 1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			break ;
		v *= 10;
		v -= *str - '0';
		str++;
	}
	v *= -(is_positive + !is_positive);
	return (v);
}
