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

/**
 * op_pchar - prints the char at the top of the stack, followed by a new line
 * @top: top of the stack
 * @line_number: the line number
 */
void op_pchar(stack_t **top, unsigned int line_number)
{
	if (isEmpty(top))
	{
		stack_empty_err(line_number, "pchar");
	}
	if (isChar((*top)->n))
		printf("%c\n", (*top)->n);
	else
		out_range_err(line_number);
}
/**
 * op_pstr - prints the string starting st the top of the stack
 * @top: top of the stack
 * @line_number: the line number
 */
void op_pstr(stack_t **top, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current;

	current = (*top);
	while (current)
	{
		if (current->n == 0 || !isChar(current->n))
			break;
		printf("%c", current->n);

		current = current->prev;
	}
	printf("\n");
}
/**
 * op_rotl - rotates the stack to the top
 * @top: top of the stack
 * @line_number: the line number
 */
void op_rotl(stack_t **top, unsigned int line_number)
{
	stack_t *begin = (*top);
	int i;

	if (isEmpty(top))
		return;

	for (i = 1; begin->prev; i++)
	{
		if (i != 1)/*if not first time*/
		{
			op_swap(&begin, line_number);
			begin = begin->prev;
		}
		else
		{
			op_swap(top, line_number);
			begin = (*top)->prev;
		}
	}
}

