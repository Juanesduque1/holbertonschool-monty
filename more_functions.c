#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_swap(sstack_t **stack, unsigned int line_number)
{
}

/**
 * f_add - Adds the top two elements of the stack
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_add(sstack_t **stack, unsigned int line_number)
{
}

/**
 * f_nop - Doesn't do anything
 * @stack: Stack of nodes
 * @line_number: Line where the instruction is located
 */

void f_nop(sstack_t **stack, unsigned int line_number)
{
	(void)(*stack);
	(void)(line_number);
}
