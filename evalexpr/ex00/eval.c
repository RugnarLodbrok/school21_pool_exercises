#include <stdlib.h>
#include "ft_list.h"
#include "str_utils.h"
#include "utils.h"
#include "tokens.h"
#include "operator.h"
#include "eval.h"

int eval_operand(char *str)
{
	char expr[ft_strlen(str) - 1];
	
	if (*str == '(')
	{
		ft_strlcpy(expr, str + 1, ft_strlen(str) - 1);
		//todo: modify str inplace as it will be used only once
		return eval(expr);
	}
	else
		return (ft_atoi(str));
}

void eval_operands(t_list *n)
{
	while (n)
	{
		n->value = eval_operand(n->str);
		n = n->next;
		if (n)
			n = n->next;
	}
}

int eval(char *str)
{
	t_list *n;
	char *token;
	int ret;
	
	n = 0;
	while (*str)
	{
		token = get_token(&str);
		if (token)
			ft_list_push_back(&n, token);
		else
			break;
	}
	print_ll(n);
	eval_operands(n);
	eval_ops(n, 1);
	eval_ops(n, 0);
	print_ll(n);
	ret = n->value;
	free(n->str);
	free(n);
	return (ret);
}
