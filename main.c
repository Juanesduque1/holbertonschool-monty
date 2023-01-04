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
	char *buff = NULL, *input = NULL;
	unsigned int line_number = 0;
	size_t size = 0;
	sstack_t *stack = NULL;

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
		input = strtok(buff, " ");
		/*printf("%s\n", input);*/
		if (input)
			get_opcode(input, &stack, line_number);
	}

	free(buff);
	fclose(fd);
	return (0);
}
