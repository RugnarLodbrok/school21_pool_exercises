#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "ft_list.h"

char *get_token(char **str)
{
	char *ret;
	char *ptr;
	
	skip_spaces(str);
	ptr = *str;
	if (!ptr)
		return (0);
	ptr = *str;
	if (*ptr == '(')
	{}
	else
		skip_non_spaces(&ptr);
	
	
	ret = malloc(sizeof(char) * (ptr - *str + 1));
	ft_strlcpy(ret, *str, (ptr - *str + 1));
	*str = ptr;
	return (ret);
}

int eval(char *str)
{
	t_list *list;
	char *token;
	
	list = 0;
	while (*str)
	{
		token = get_token(&str);
		if (token)
			ft_list_push_back(&list, token);
		else
			break;
	}
	print_ll(list);
	return 0;
}

int main()
{
	char *expr;
	
	expr = "1 + 2";
	printf("\nEVAL: `%s`\n", expr);
	eval(expr);
	return (0);
}