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
		/*printf("line %d\n", l_num);*/
		if (!cmnd)
		{
			/*printf("-------------------\n");*/
			continue;
		}
		check_opcode(cmnd, &stack, l_num);
		/*printf("-------------------\n");*/
	}
	fclose(fp);
	/*printf("file closed\n");*/
	if (line)
		free(line);
	/*printf("line freed\n");*/
	free_stack(&stack);
	exit(EXIT_SUCCESS);
}

