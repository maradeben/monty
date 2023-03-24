#include "monty.h"

globals global;

/**
 * main - Start LIFO, FILO program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	char *opcode;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (init_globals(&global) != 0)
		return (EXIT_FAILURE);

	global.file = fopen(argv[1], "r");
	if (!global.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_all();
		return (EXIT_FAILURE);
	}

	while (getline(&global.buff, &global.tmp, global.file) != EOF)
	{
		opcode = strtok(global.buff, " \r\t\n");
		if (opcode != NULL)
			if (get_funct(&global, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		global.line++;
	}

	free_all();

	return (EXIT_SUCCESS);
}
