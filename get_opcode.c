#include "monty.h"

void get_opcode(char *opcode, stack_t *stack)
{
	int i;
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		{NULL,NULL}
	};

	for (i = 0; ops[i] != NULL; i++)
	{
		if (ops[i].opcode == opcode)
		{
			ops[i].f(stack);
		}
	}
}