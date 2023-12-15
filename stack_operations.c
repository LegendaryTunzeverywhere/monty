#include "monty.h"

/**
 * mod_nodes - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function that performs modulus on the top two
 * elements of the stack.
 *
 * Return: Nothing (void)
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int plus;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_num, "mod");


	if ((*stack)->n == 0)
		_err(9, line_num);
	(*stack) = (*stack)->next;
	plus = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = plus;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function that multiplies the top two 
 * element nodes of the stack
 *
 * Return: Nothing (void)
 */
void mul_nodes(stack_t **stack, unsigned int line_num)
{
	int plus;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_num, "mul");

	(*stack) = (*stack)->next;
	plus = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = plus;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
