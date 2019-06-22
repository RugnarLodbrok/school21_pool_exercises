#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "ft_list.h"
#include "ops.h"
#include "main.h"

typedef struct	s_opp
{
	char *literal;
	void *f;
}				t_opp;

t_opp g_opptab[] =
{
	{"-", &ft_sub},
	{"+", &ft_add},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod}
};

char *skip_par_block(char *str)
{
	int n;
	
	n = 0;
	while (*str)
	{
		if (*str == '(')
			n++;
		if (*str == ')')
			n--;
		str++;
		if (!n)
			break ;
	}
	return (str);
}

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
		ptr = skip_par_block(ptr);
	else
		skip_non_spaces(&ptr);
	
	
	ret = malloc(sizeof(char) * (ptr - *str + 1));
	ft_strlcpy(ret, *str, (ptr - *str + 1));
	*str = ptr;
	return (ret);
}

int eval_operand(char *str)
{
	//char expr[ft_strlen(str) - 2];
	
	if (*str == '(')
	{
		//ft_strlcpy(expr, str + 1, ft_strlen(str) - 2);
		//printf("recur eval: `%s`\n, expr");
		return 0;
		//return eval(expr);
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

void	*resolve_operator(char *str)
{
	int		i;
	void	*f;

	f = 0;
	i = 0;
	while (i < 5)
	{
		if (!ft_strcmp(g_opptab[i].literal, str))
			f = g_opptab[i].f;
		else if (!ft_strcmp(g_opptab[i].literal, "") && !f)
			f = g_opptab[i].f;
		i++;
	}
	return (f);
}

int eval_op(char *str, int a, int b)
{
	int ret;
	int (*op)(int, int);
	op = resolve_operator(str);
	ret = op(a, b);
	return (ret);
}

int is_hp(char *str)
{
	str++;//TODO
	return (0);
}

void eval_ops(t_list *n, int hp)
{
	while(n->next)
	{
		if (!hp || is_hp(n->next->str))
		{
			n->value = eval_op(n->next->str, n->value, n->next->next->value);
			n->next = n->next->next->next; //TODO: delete via linked list's remove element
			//ft_list_remove_next(n);
			//ft_list_remove_next(n);
		}
		else
			n = n->next->next;
	}
}

int eval(char *str)
{
	t_list *n;
	char *token;
	
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
	eval_ops(n, 0);
	print_ll(n);
	return (n->value);
}

int main()
{
	char *expr;
	
	expr = "1 + 2 - (3 - 2)";
	printf("\nEVAL: `%s`\n", expr);
	printf(" = %d\n", eval(expr));
	return (0);
}