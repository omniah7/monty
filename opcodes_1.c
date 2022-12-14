#include "monty.h"

/**
 * op_push - pushes an element to the stack
 * @top: top of the stack
 * @line_number: the line number
 */
void op_push(stack_t **top, unsigned int line_number)
{
	char *argument;

	argument = strtok(NULL, "\n\t\r ");

	if (argument == NULL || !isInteger(argument))
	{
		err_invalid_push(line_number);
	}
	push(top, toInteger(argument));
}
/**
 * op_pall - prints all the values on the stack, starting from the top
 * @top: top of the stack
 * @line_number: the line number
 */
void op_pall(stack_t **top, __attribute__((unused)) unsigned int line_number)
{
	stack_t *node = (*top);

	if (isEmpty(top))
		return;

	while (node)
	{
		printf("%d\n", node->n);
		node = node->prev;
	}
}
/**
 * op_pint - prints the value at the top of the stack, followed by a new line
 * @top: top of the stack
 * @line_number: the line number
 */
void op_pint(stack_t **top, unsigned int line_number)
{
	if (isEmpty(top))
	{
		stack_empty_err(line_number, "pint");
	}
	printf("%d\n", (*top)->n);
}
/**
 * op_pop - removes the top element of the stack
 * @top: top of the stack
 * @line_number: the line number
 */
void op_pop(stack_t **top, unsigned int line_number)
{
	if (isEmpty(top))
	{
		pop_stack_empty_err(line_number);
	}
	pop(top);
}

/**
 * op_swap - swaps the top two elements of the stack
 * @top: top of the stack
 * @line_number: the line number
 */
void op_swap(stack_t **top, unsigned int line_number)
{
	stack_t *tmp;

	if (isEmpty(top) || !(*top)->prev)
	{
		stack_short_err(line_number, "swap");
	}
	tmp = (*top)->prev->prev;

	(*top)->prev->next = (*top)->next;/*NULL*/
	(*top)->next = (*top)->prev;
	(*top)->prev->prev = (*top);
	(*top)->prev = tmp;

	/*if stack is not 2 elements*/
	if (tmp)
	{
		tmp->next = (*top);
	}
	/*if next elemnt after the two swaped elements is not NULL*/
	if ((*top)->next->next)
	{
		(*top)->next->next->prev = (*top)->next;
	}
	(*top) = (*top)->next;
}

