#include "monty.h"

/**
 * main - monty interpreter
 * @argc: number of arguments
 * @argv: arguments vector
 * Return: EXIT_SUCCESS or EXIT_FAILED
 */
int main(int argc, char *argv[])
{
	FILE *fp;

	if (argc != 2)
	{
		err_argc();
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		err_openFile(argv[1]);
	}

	readFile(fp);

	return (EXIT_SUCCESS);

}

