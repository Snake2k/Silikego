#include <stdio.h>
#include "xvcalc.h"

int main(int argc, char *argv[])
{
	xvcalc_status status;
	char * expression;

	if (argc >= 2)
		expression = argv[1];
	else
		expression = "";

	status = xvcalc(expression);
	switch (status) {
	case S_INTEGER:
		printf("Value: %i\n", xvcalc_get_int());
		break;
	case S_FLOAT:
		printf("Value: %f\n", xvcalc_get_float());
		break;
	case E_SYNTAX:
		printf("Syntax error.");
		break;
	case E_MEMORY:
		printf("Out of memory.");
		break;
	case E_ZERO_DIV:
		printf("Division by zero error.");
		break;
	case E_FUNCTION:
		printf("Function not found.");
		break;
	case E_ARGUMENTS:
		printf("Bad argument count.");
		break;
	}
	xvcalc_clean();
	return 0;
}
