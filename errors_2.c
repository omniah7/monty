#include "monty.h"
/**
 * pint_stack_empty_err - error message
 * @line: the line number
 */
void pint_stack_empty_err(int line)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line);
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

