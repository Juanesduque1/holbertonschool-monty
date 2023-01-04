#include "monty.h"

/**
 * f_pall - Prints all the values of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_pall(sstack_t **stack, unsigned int line_number)
{
	sstack_t *aux;

	(void)(line_number);

	aux = *stack;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * f_push - Pushes an element at the top of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_push(sstack_t **stack, unsigned int line_number)
{
	sstack_t *new;
	char integer;

	printf("hello\n");
	new = malloc(sizeof(sstack_t));
	if (!new)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(&integer);
	new->prev = NULL;
	new->next = *stack;
}

/**
 * f_pint - Prints the first node of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_pint(sstack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		dprintf(2, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
