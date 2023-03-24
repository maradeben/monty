#include "monty.h"

/**
 * pall - print the stack
 * @stack: pointer to the head of the linked list
 * @line: current line in file
 */
void pall(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;
	(void) line;

	if (!tmp)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * push - add element to top of stack
 * @stack: pointer to the head of the linked list
 * @line: current line in file
 */
void push(stack_t **stack, unsigned int line)
{
	stack_t *tmp = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp->n = atoi(num);
	if (global.MODE == 0 || !*stack)
	{
		tmp->next = *stack;
		tmp->prev = NULL;
		if (*stack)
			(*stack)->prev = tmp;
		*stack = tmp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = tmp;
		tmp->prev = tm;
		tmp->next = NULL;
	}
}

/**
 * pint - print element at top of stack
 * @stack: pointer to the head of the linked list
 * @line: current line in file
 */
void pint(stack_t **stack, unsigned int line)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - delete element at top of stack
* @stack: pointer to the head of the linked list
* @line: current line in file
*/
void pop(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}
