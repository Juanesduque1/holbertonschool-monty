#include "monty.h"

/**
*main - Main function
*@argc: Quantity of arguments that enter the function
*@argv: Arguments
*Return: Always Zero
*/

int main (int argc, char **argv)
{
	FILE *fd;
	char *buff = NULL;
	size_t size = 0;
	ssize_t getsize = 0;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file");
        exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r+");

	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
	}

	getsize = getline(&buff, &size, fd);
	while (getsize != -1)
	{
		printf("%s", buff);
	}

	free(buff);
	fclose(fd);
	return (0);
}
