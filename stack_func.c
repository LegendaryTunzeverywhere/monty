#include "monty.h"

/**
 * add_to_stack - Entry point
 * @new_node: ptr to the new node.
 * @ln: integer that represents the line num of of the opcode.
 *
 * Description: function that adds a node to the stack
 * Return: Nothing (void)
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_stack - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: line number of the opcode.
 *
 * Description: function that prints a node of a stack
 * Return: Nothing (void).
 */
void print_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_top - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function that puts a node to the top of a stack
 * Return: Nothing (void)
 */
void pop_top(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		_err(7, line_num);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_top - Entry point
 * @stack: ptr to a ptr that points to top node of the stack.
 * @line_num: integer that represents the line number of of the opcode.
 *
 * Description: function that prints the top node of a stack.
 * Return: Nothing (void)
 */
void print_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		_err(6, line_num);
	printf("%d\n", (*stack)->n);
}
