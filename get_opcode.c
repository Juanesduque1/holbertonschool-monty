#include "monty.h"

void get_opcode(char *buff, stack_t *stack)
{
	int i, line_number;
	char *divstring;
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		{NULL,NULL}
	};

	divstring = strtok(&buff, ' ');

	for (i = 0; ops[i] != NULL; i++)
	{
		if (ops[i].opcode == divstring[0])
		{
			ops[i].f(stack, line_number);
		}
	}
}