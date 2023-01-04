#include "monty.h"

/**
*main - Main function
*@argc: Quantity of arguments that enter the function
*@argv: Arguments
*Return: Always Zero
*/

void f_pall(stack_t *stack, unsigned int line_number)
{

	if (!stack)
		return;

	while (stack)
	{
		printf("%s\n", stack->n);
		
	}

}