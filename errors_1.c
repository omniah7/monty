#include "monty.h"
/**
 * err_openFile - error message
 * @filename: the file name
 */
void err_openFile(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}
/**
 * err_argc - error message
 */
void err_argc(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
/**
 * err_invalid_push - error message
 * @line: the line number
 */
void err_invalid_push(int line)
{
	fprintf(stderr, "L%d: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
/**
 * err_invalid_instruction - error message
 * @line: the line number
 * @opcode: the action given
 */
void err_invalid_instruction(int line, char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}
/**
 * err_malloc - error message
 */
void err_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

