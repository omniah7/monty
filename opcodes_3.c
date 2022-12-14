#include "monty.h"
/**
 * op_mod - computes the remainder of the second top element by the top element
 * @top: top of the stack
 * @line_number: the line number
 */
void op_mod(stack_t **top, unsigned int line_number)
{
	if (isEmpty(top) || !(*top)->prev)
	{
		stack_short_err(line_number, "mod");
	}
	if ((*top)->n == 0)
	{
		zero_division_err(line_number);
	}
	(*top)->prev->n %= (*top)->n;
	pop(top);
}
