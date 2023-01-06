#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *aux = *stack;

	if (!*stack || !stack || !head->next)
	{
		dprintf(2, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = head->next;
	head->prev = NULL;

	aux->next = head->next;
	head->next = aux;
	(head->next)->prev = head;

	*stack = head;
}

/**
 * f_add - Adds the top two elements of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if (!*stack || !stack || !aux->next)
	{
		dprintf(2, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(aux->next)->n += aux->n;
	f_pop(&aux, line_number);

	*stack = aux;
}

/**
 * f_nop - Doesn't do anything
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_nop(stack_t **stack, unsigned int line_number)
{
	(void)(*stack);
	(void)(line_number);
}

/**
 * free_stack - Frees a stack when terminating
 * @stack: Stack
 */

void free_stack(stack_t *stack)
{
	stack_t *aux;

	while (stack != NULL)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}
