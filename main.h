#ifndef _MAIN_H_
#define _MAIN_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*opfunc)(stack_t **, unsigned int);

/*file uitility*/
void open_file(char *filename);
void read_file(FILE *);
int parse_line(char *buff, int line_num, int fmt);
void find_funcs(char *, char *, int, int);
void call_func(op_func, char *, char *, int, int);
int len_chars(FILE *);

/*stack utility*/
void free_nodes(void);
stack_t *create_node(int n);
void add_to_queue(stack_t **, unsigned int);
void print_stack(stack_t **, unsigned int);
void add_to_stack(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);

void add_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul_nodes(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);

void print_char(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);

void err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_t **, unsigned int);
void more_err(int error_code, ...);


#endif
