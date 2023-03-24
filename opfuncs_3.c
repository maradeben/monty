#include "monty.h"

/**
 * mul - s
 * @stack: pointer to head of the doubly linked list
 * @line: current line in file
 */
void mul(stack_t **stack, unsigned int line)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line);
}


/**
 * mod - perform n2 % n1
 * @stack: pointer to head of the doubly linked list
 * @line: current line in file
 */
void mod(stack_t **stack, unsigned int line)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line);
}

/**
 * pchar - print topmost element as a char
 * @stack: pointer to head of the doubly linked list
 * @line: current line in file
 */
void pchar(stack_t **stack, unsigned int line)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (isascii((*stack)->n))
	{
		printf("%c\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * pstr - print the topmost string represented in the stack
 * @stack: pointer to head of the doubly linked list
 * @line: current line in file
 */
void pstr(stack_t **stack, unsigned int line)
{
	stack_t *tmp = *stack;
	(void) line;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (tmp)
	{
		if ((tmp->n == 0) || (!isascii((tmp)->n)))
			break;
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
