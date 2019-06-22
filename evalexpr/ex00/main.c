#include <stdio.h>
#include <stdlib.h>
#include "eval.h"


int main()
{
	char *expr;
	
	//expr = "1 + 2 - (3 - 2)";
	expr = "(1 + (3 - 2)) + 2 * 2";
	printf("\nEVAL: `%s`\n", expr);
	printf(" = %d\n", eval(expr));
	return (0);
}