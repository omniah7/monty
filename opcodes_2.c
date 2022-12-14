#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 * @top: top of the stack
 * @line_number: the line number
 */
void op_add(stack_t **top, unsigned int line_number)
{

	if (isEmpty(top) || !(*top)->prev)
	{
		stack_short_err(line_number, "add");
	}
	(*top)->prev->n += (*top)->n;
	pop(top);
}
/**
 * op_nop - doesn’t do anything
 * @top: top of the stack
 * @line_number: the line number
 */
void op_nop(__attribute__((unused)) stack_t **top,
__attribute__((unused)) unsigned int line_number)
{}

/**
 * op_sub - subtracts the top element from the second top element of the stack
 * @top: top of the stack
 * @line_number: the line number
 */
void op_sub(stack_t **top, unsigned int line_number)
{
	if (isEmpty(top) || !(*top)->prev)
	{
		stack_short_err(line_number, "sub");
	}
	(*top)->prev->n -= (*top)->n;
	pop(top);
}

/**
 * op_div - divides the second top element by the top element of the stack
 * @top: top of the stack
 * @line_number: the line number
 */
void op_div(stack_t **top, unsigned int line_number)
{
	if (isEmpty(top) || !(*top)->prev)
	{
		stack_short_err(line_number, "div");
	}
	if ((*top)->n == 0)
	{
		zero_division_err(line_number);
	}
	(*top)->prev->n /= (*top)->n;
	pop(top);
}

/**
 * op_mul - multiplies the second top element with the top element of a stack
 * @top: top of the stack
 * @line_number: the line number
 */
void op_mul(stack_t **top, unsigned int line_number)
{
	if (isEmpty(top) || !(*top)->prev)
	{
		stack_short_err(line_number, "mul");
	}

	(*top)->prev->n *= (*top)->n;
	pop(top);
}
