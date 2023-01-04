#include "monty.h"

void get_opcode(char *buff, sstack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{NULL,NULL}
	};
	/*printf("gets here\n%s %d\n", buff, line_number);*/
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		/*printf("hi\n");*/
		if (strcmp(ops[i].opcode, buff) == 0)
		{
			/*printf("enters\n%s\n", buff);*/
			ops[i].f(stack, line_number);
			return;
		}
	}
	dprintf(2, "L%i: unknown instruction %s\n", line_number, buff);
	exit(EXIT_FAILURE);
}
