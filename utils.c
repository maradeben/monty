#include "monty.h"

/**
 * init_globals - initialize the global variables
 * @global: struct of global variables
 * Return: 0 on Success, 1 on Failure
 */
int init_globals(globals *global)
{
	global->file = NULL;
	global->buff = NULL;
	global->tmp = 0;
	global->dict = map_funcs();
	if (global->dict == NULL)
		return (EXIT_FAILURE);
	global->head = NULL;
	global->line = 1;
	global->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * map_funcs - associate functions with their opcodes
 * Return: pointer to the functions map
 */
instruction_t *map_funcs()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[4].opcode = "swap", ptr[4].f = swap;
	ptr[5].opcode = "add", ptr[5].f = add;
	ptr[6].opcode = "nop", ptr[6].f = NULL;
	ptr[7].opcode = "sub", ptr[7].f = sub;
	ptr[8].opcode = "div", ptr[8].f = divi;
	ptr[9].opcode = "mul", ptr[9].f = mul;
	ptr[10].opcode = "mod", ptr[10].f = mod;
	ptr[11].opcode = "pchar", ptr[11].f = pchar;
	ptr[12].opcode = "pstr", ptr[12].f = pstr;
	ptr[13].opcode = "rotl", ptr[13].f = rotl;
	ptr[14].opcode = "rotr", ptr[14].f = rotr;
	ptr[15].opcode = "stack", ptr[15].f = stack;
	ptr[16].opcode = "queue", ptr[16].f = queue;
	ptr[17].opcode = NULL, ptr[17].f = NULL;

	return (ptr);
}

/**
 * get_funct - call functions corresponding to opcodes
 * @global: Global variables
 * @opcode: Command to execute
 * Return: None
 */
int get_funct(globals *global, char *opcode)
{
	int i;

	for (i = 0; global->dict[i].opcode; i++)
		if (strcmp(opcode, global->dict[i].opcode) == 0)
		{
			if (!global->dict[i].f)
				return (EXIT_SUCCESS);
			global->dict[i].f(&global->head, global->line);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			global->line, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * free_all - Clean all program mallocs
 * Return: None
 */
void free_all(void)
{
	if (global.buff != NULL)
		free(global.buff);
	if (global.file != NULL)
		fclose(global.file);
	free(global.dict);
	if (global.head != NULL)
	{
		while (global.head->next != NULL)
		{
			global.head = global.head->next;
			free(global.head->prev);
		}
		free(global.head);
	}
}

/**
 * _isdigit - check if string can be number
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}

