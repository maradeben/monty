#include "monty.h"

/**
 * swap - swap top two elements in stack
 * @stack: pointer to the head of the doubly linked list
 * @line: current line in file
 */
void swap(stack_t **stack, unsigned int line)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * add - add topmost to second topmost and remove topmost
 * @stack: pointer to the head of the doubly linked list
 * @line: current line in file
 */
void add(stack_t **stack, unsigned int line)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line);
}

/**
 * sub - subtract topmost from second topmost and remove topmost
 * @stack: pointer to the head of the doubly linked list
 * @line: Line counter
 */
void sub(stack_t **stack, unsigned int line)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line);
}

/**
 * divi - divide the top two elements of the stack
 * @stack: pointer to the head of the doubly linked list
 * @line: File line counter
 */
void divi(stack_t **stack, unsigned int line)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	pop(stack, line);
}
