#include "monty.h"

/**
 * print_char - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function that prints the ascii value from char
 * from 0 to 127
 *
 * Return: Nothing (void)
 */
void print_char(stack_t **stack, unsigned int line_num)
{
	int a;

	if (stack == NULL || *stack == NULL)
		str_err(11, line_num);

	a = (*stack)->n;
	if (a < 0 || a > 127)
		str_err(10, line_num);
	printf("%c\n", a);
}

/**
 * print_str - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @ln: integer that represents the line number of of the opcode.
 *
 * Description: function that prints strings
 * Return: Nothing (void)
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int a;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		a = temp->n;
		if (a <= 0 || a > 127)
			break;
		printf("%c", a);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotr - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @ln: integer that represents the line number of of the opcode.
 *
 * Description: function that rotates the last node of the stack to the top
 * Return: Nothing (void)
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}

/**
 * rotl - Entry point
 * @stack:  ptr to a ptr that points to top node of the stack.
 * @ln: integer that represents the line number of of the opcode.
 *
 * Description: function that rotates the first node of the stack to the last.
 * Return: Nothing (void)
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


