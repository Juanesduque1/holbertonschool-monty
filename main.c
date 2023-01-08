#include "monty.h"

/**
*main - Main function
*@argc: Quantity of arguments that enters the function
*@argv: Arguments
*Return: Always Zero
*/

int main(int argc, char **argv)
{
	FILE *fd;
	unsigned int line_number = 0;
	char *buff;
	size_t size = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r+");

	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&buff, &size, fd) != -1)
	{
		line_number++;
		input = _divstring(buff, "\n\t\r ");
		if (input)
			get_opcode(input[0], &stack, line_number);

		free(input);
	}

	free(buff);
	free_stack(stack);
	fclose(fd);
	return (0);
}
