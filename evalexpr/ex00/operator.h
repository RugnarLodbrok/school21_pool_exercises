#ifndef OPERATOR_H

# define OPERATOR_H

#include "ops.h"

typedef struct	s_opp
{
	char *literal;
	void *f;
}				t_opp;

void eval_ops(t_list *n, int hp);

#endif
