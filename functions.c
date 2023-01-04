#include "monty.h"

/**
 * f_pall - prints all the values on the stack
 * @stack: stack
 * @line_number: line where the instruction is located
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

/**
 * f_push - pushes an element to the stack
 * @stack: stack
 * @line_number: line where the instruction is located
 */
void f_push(sstack_t **stack, unsigned int line_number)
{
	sstack_t *new;
	char integer;

	new = (sstack_t *)malloc(sizeof(sstack_t));
	if (!new)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(integer);
	new->prev = NULL;
	new->next = *stack;
}
