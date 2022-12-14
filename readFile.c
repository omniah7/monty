#include "monty.h"
/**
 * readFile - reads a file line by line
 * @fp: the top of the stack
 */
void readFile(FILE *fp)
{
	int l_num, read;
	char *line, *cmnd;
	stack_t *stack = NULL;
	size_t len = 0;

	for (l_num = 1; (read = getline(&line, &len, fp)) != EOF; l_num++)
	{
		cmnd = strtok(line, "\n\t\r ");

		if (!cmnd)
		{
			continue;
		}
		if (!check_opcode(cmnd, &stack, l_num))
		{
			fclose(fp);
			if (line)
				free(line);
			free_stack(&stack);
			err_invalid_instruction(l_num, cmnd);
		}
	}
	fclose(fp);

	if (line)
		free(line);

	free_stack(&stack);
	exit(EXIT_SUCCESS);
}

