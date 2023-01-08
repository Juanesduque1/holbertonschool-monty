#include "monty.h"

/**
*get_opcode - Function to check opcode
*@buff: Line which has opcode and arguments
*@stack: Stack of nodes
*@line_number: Current line number
*Return: Always Zero
*/

void get_opcode(char *buff, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t ops[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{NULL, NULL}
	};

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, buff) == 0)
		{
			ops[i].f(stack, line_number);
			return;
		}
	}
	dprintf(2, "L%i: unknown instruction %s\n", line_number, buff);
	exit(EXIT_FAILURE);
}
/**
**_divstring - Auxiliar function to divide a string
*@string: String that is going to be divided
*@separator: Separator that indicates the division point
*Return: Divided array
*/

char **_divstring(char *string, char *separator)
{
	int i = 0, j = 0;
	char *t, **array;

	array = (char **)calloc(100, sizeof(char *));

	if (!array)
	{
		free(array);
		dprintf(2, "Error: calloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (string[i])
		i++;
	while ((t = strtok(string, separator)) != NULL)
	{
		array[j] = t;
		string = NULL;
		j++;
	}
	return (array);
}
