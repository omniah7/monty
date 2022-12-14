#include "monty.h"
/**
 * check_opcode - search for the commmand and executes it
 * @cmnd: the command to be executed
 * @stack: the top of a stack
 * @line: number of the line
 * Return: true if executed, false otherwise
 */
bool check_opcode(char *cmnd, stack_t **stack, unsigned int line)
{
	int i;
	instruction_t opcodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"#", op_nop},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", op_rotl},
		{NULL, NULL}
	};

	for (i = 0; opcodes[i].opcode != NULL ; i++)
	{
		if (strncmp(opcodes[i].opcode, cmnd, strlen(opcodes[i].opcode)) == 0)
		{
			opcodes[i].f(stack, line);
			return (true);
		}
	}
	return (false);
}

