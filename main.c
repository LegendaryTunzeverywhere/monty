#include "monty.h"

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0 (on Success)
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * free_nodes - Entry point
 *
 * Description: Frees the nodes in the stack.
 * Return: Nothing (void).
 */
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * create_node - Entry point
 * @n: Number to go inside the node.
 *
 * Description: Creates a node.
 *
 * Return: On Success a pointer to the node,
 * if failed return NULL.
 */
stack_t *create_node(int n)
{
	stack_t *nodes;

	nodes = malloc(sizeof(stack_t));
	if (nodes == NULL)
		err(4);
	nodes->next = NULL;
	nodes->prev = NULL;
	nodes->n = n;
	return (nodes);
}

/**
 * add_to_queue - Entry point
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 *
 * Description: adds a node to the queue.
 * Return: Noting (Void)
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}
