#include "monty.h"

/**
 * open_file - Entry point
 * @filename: the file namepath to be opened
 *
 * Description: Function that opens a file.
 * Return: Nothing (void)
 */
void open_file(char *filename)
{
	FILE *fd = fopen(filename, "r");

	if (filename == NULL || fd == NULL)
		err(2, filename);

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - Entry point
 * @fd: pointer to file descriptor
 *
 * Description: function that reads a file.
 * Return: Nothing (void)
 */
void read_file(FILE *fd)
{
	int fmt = 0, line_num;
	char *buff = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buff, &len, fd) != -1; ++line_num)
	{
		fmt = parse_line(buff, line_num, fmt);
	}
	free(buff);
}

/**
 * parse_line - Entry point
 * @buff: line from the file
 * @line_num: line number
 * @fmt:  storage format. If 0, Nodes will be entered as a stack.
 * if 1, Nodes will be entered as a queue.
 *
 * Description: Split each lines into tokens to select which function
 * to call up.
 *
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int parse_line(char *buff, int line_num, int fmt)
{
	char *opcode, *no;
	const char *delim = "\n ";

	if (buff == NULL)
		err(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (fmt);
	no = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_funcs(opcode, no, line_num, fmt);
	return (fmt);
}

/**
 * find_funcs - Entry point
 * @opcode: opcode
 * @no: argument of opcode
 * @ln: line number
 * @fmt:  storage format. If 0, Nodes will be entered as a stack,
 * if 1, nodes will be entered as a queue.
 *
 * Description: function that find the appropriate function for the opcode
 *
 * Return: Nothing (void)
 */
void find_funcs(char *opcode, char *no, int ln, int fmt)
{
	int a;
	int log;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (log = 1, a = 0; func_list[a].opcode != NULL; ++a)
	{
		if (strcmp(opcode, func_list[a].opcode) == 0)
		{
			call_func(func_list[a].f, opcode, no, ln, fmt);
			log = 0;
		}
	}
	if (log == 1)
		err(3, ln, opcode);
}

/**
 * call_func - Entry point
 * @func: Ptr to the function that is about to be called.
 * @op: str that represents the opcode.
 * @no: str that represents a numeric value.
 * @ln: line numeber of the instruction passed
 * @fmt: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 *
 * Description: function that calls the required function.
 * Return: Nothing (void)
 */
void call_func(opfunc func, char *op, char *no, int ln, int fmt)
{
	stack_t *node;
	int log;
	int a;

	log = 1;
	if (strcmp(op, "push") == 0)
	{
		if (no != NULL && no[0] == '-')
		{
			no = no + 1;
			log = -1;
		}
		if (no == NULL)
			err(5, ln);
		for (a = 0; no[a] != '\0'; ++a)
		{
			if (isdigit(no[a]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(no) * log);
		if (fmt == 0)
			func(&node, ln);
		if (fmt == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
