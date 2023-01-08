#include "monty.h"

/**
 * f_pall - Prints all the values of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_pall(stack_t **stack, unsigned int line_number)
{

	(void)(line_number);

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}

/**
 * f_push - Pushes an element at the top of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_push(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = NULL;
	int integer;

	aux = malloc(sizeof(stack_t));
	if (aux == NULL)
	{
		free(aux);
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	integer = atoi(input[1]);
	if (integer == 0)
	{
		dprintf(2, "L%i: usage: push integer\n", line_number);
		free(aux);
		exit(EXIT_FAILURE);
	}

	aux->n = integer;
	aux->prev = NULL;
	aux->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = aux;
	*stack = aux;
}

/**
 * f_pint - Prints the first node of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		dprintf(2, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * f_pop- Removes the top element of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (!*stack || !stack)
	{
		dprintf(2, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = aux->next;
		(*stack)->prev = NULL;
		free(aux);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
