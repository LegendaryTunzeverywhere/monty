#include "monty.h"

/**
 * nop - Entry point
 * @stack: ptr to a ptr that points to the top node of the stack.
 * @line_num: integer that represents the line number of the opcode.
 *
 * Description: nop function
 * Return: Nothing (void)
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}

/**
 * add_nodes - Entry point
 * @stack: ptr to a ptr that points to the top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function that adds top two element of the stack
 * Return: Nothing (void)
 */
void add_nodes(stack_t **stack, unsigned int line_num)
{
	int plus;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_num, "add");

	(*stack) = (*stack)->next;
	plus = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = plus;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * swap_nodes - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function thats swaps the top two element of a stack
 * Return: Nothing (void)
 */
void swap_nodes(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * div_nodes - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function that divides the top two elements of the stack.
 */
void div_nodes(stack_t **stack, unsigned int line_num)
{
	int plus;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_num, "div");

	if ((*stack)->n == 0)
		_err(9, line_num);
	(*stack) = (*stack)->next;
	plus = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = plus;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - Entry point.
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function that sub the top two elements of the stack.
 * Return: Nothing (void)
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int plus;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_err(8, line_number, "sub");

	(*stack) = (*stack)->next;
	plus = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = plus;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
