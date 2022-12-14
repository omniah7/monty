#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


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
/*extern char *line;*/

/* readFile */
void readFile(FILE *fp);

/* errors_1 */
void err_openFile(char *filename);
void err_argc(void);
void err_invalid_instruction(int line, char *opcode);
void err_invalid_push(int line);
void err_malloc(void);
/* errors_2 */
void stack_empty_err(int line, char *s);
void pop_stack_empty_err(int line);
void stack_short_err(int line, char *s);
void zero_division_err(int line);
void out_range_err(int line);
/*errors_3*/



/* check_opcodes */
bool check_opcode(char *cmnd, stack_t **stack, unsigned int line);




/* opcodes_1 */
void op_push(stack_t **top, unsigned int line_number);
void op_pall(stack_t **top, unsigned int line_number);
void op_pint(stack_t **top, unsigned int line_number);
void op_pop(stack_t **top, unsigned int line_number);
void op_swap(stack_t **top, unsigned int line_number);
/* opcodes_2 */
void op_add(stack_t **top, unsigned int line_number);
void op_nop(stack_t **top, unsigned int line_number);
void op_sub(stack_t **top, unsigned int line_number);
void op_div(stack_t **top, unsigned int line_number);
void op_mul(stack_t **top, unsigned int line_number);
/* opcodes_3 */
void op_mod(stack_t **top, unsigned int line_number);
void op_pchar(stack_t **top, unsigned int line_number);
void op_pstr(stack_t **top, unsigned int line_number);
void op_rotl(stack_t **top, unsigned int line_number);

/* stack functions */
void push(stack_t **top, int data);
void pop(stack_t **top);
bool isEmpty(stack_t **top);
void free_stack(stack_t **top);
void reverse(stack_t **top);
/* utilities */
int toInteger(char *s);
bool isInteger(char *s);
bool isChar(int c);


#endif
