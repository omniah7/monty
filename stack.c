#include "monty.h"
/**
 * push - insert a new element at the top of a stack
 * @top: the top of the stack
 * @data: the integer to be pushed
 */
void push(stack_t **top, int data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		err_malloc();
	}
	new->n = data;
	new->next = NULL;
	if (isEmpty(top))
	{
		new->prev = NULL;
		(*top) = new;
		/*printf("push %d\n", (*top)->n);*/
		return;
	}

	new->prev = (*top);
	(*top)->next = new;
	(*top) = new;
	/*printf("push %d\n", (*top)->n);*/
}

/**
 * pop - deletes the top element from a stack
 * @top: the top of the stack
 */
void pop(stack_t **top)
{
	stack_t *tmp;

	if (isEmpty(top))
		return;
	tmp = (*top);
	/*if stack is more than one node*/
	if ((*top)->prev)
	{
		(*top)->prev->next = NULL;
	}

	(*top) = (*top)->prev;
	free(tmp);
}
/**
 * isEmpty - checks if a stack is empty
 * @top: the top of the stack
 * Return: true if empty, false otherwise
 */
bool isEmpty(stack_t **top)
{
	if (!top || !(*top))
		return (true);
	return (false);
}
/**
 * free_stack - free a stack
 * @top: the top of the stack
 */
void free_stack(stack_t **top)
{
	stack_t *tmp;

	while (!isEmpty(top))
	{
		tmp = (*top);
		(*top) = (*top)->prev;
		free(tmp);
	}
	/*  printf("freed stack successfully\n"); */
}

