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
