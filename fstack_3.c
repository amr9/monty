#include "monty.h"

/**
 * MulNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void MulNodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ErrorTwo(8, line_number, "mul");

	(*stack) = (*stack)->next;
	s = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * ModNodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void ModNodes(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		ErrorTwo(8, line_number, "mod");

	if ((*stack)->n == 0)
		ErrorTwo(9, line_number);
	(*stack) = (*stack)->next;
	s = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
