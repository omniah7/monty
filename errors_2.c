#include "monty.h"
/**
 * stack_empty_err - error message
 * @line: the line number
 * @s: the action given
 */
void stack_empty_err(int line, char *s)
{
	fprintf(stderr, "L%d: can't %s, stack empty\n", line, s);
	exit(EXIT_FAILURE);
}
/**
 * pop_stack_empty_err - error message
 * @line: the line number
 */
void pop_stack_empty_err(int line)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line);
	exit(EXIT_FAILURE);
}
/**
 * stack_short_err - error message
 * @line: the line number
 * @s: the action given
 */
void stack_short_err(int line, char *s)
{
	fprintf(stderr, "L%d: can't %s, stack too short\n", line, s);
	exit(EXIT_FAILURE);
}
/**
 * zero_division_err - error message
 * @line: the line number
 */
void zero_division_err(int line)
{
	fprintf(stderr, "L%d: division by zero\n", line);
	exit(EXIT_FAILURE);
}
/**
 * out_range_err - error message
 * @line: the line number
 */
void out_range_err(int line)
{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
	exit(EXIT_FAILURE);
}
