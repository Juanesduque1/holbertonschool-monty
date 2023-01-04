#include "monty.h"

/**
*main - Main function
*@argc: Quantity of arguments that enter the function
*@argv: Arguments
*Return: Always Zero
*/

void f_pall(sstack_t **stack, unsigned int line_number)
{
	sstack_t *aux;

	(void)(line_number);

	if (!stack)
		return;

	aux = *stack;

	while (stack)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}

}

void f_push(sstack_t **stack, unsigned int line_number)
{

}