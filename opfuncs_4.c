#include "monty.h"

/**
 * rotl - top to last, second top to top
 * @stack: pointer to head of doubly linked list
 * @line_number: current line in file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tm = *stack;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;
	(*stack)->next->prev = NULL;
	while (tm->next)
		tm = tm->next;
	tm->next = *stack;
	(*stack) = (*stack)->next;
	tm->next->next = NULL;
	tm->next->prev = tm;
}

/**
 * rotr - reverse the order
 * @stack: pointer to head of doubly linked list
 * @line_number: current line in file
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;

	(*stack)->prev = tmp;
	*stack = tmp;

}

/**
 * stack - s
 * @stack: pointer to head of doubly linked list
 * @line_number: current line in file
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	global.MODE = 0;
}

/**
 * queue - s
 * @stack: pointer to head of doubly linked list
 * @line_number: current line in file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;

	global.MODE = 1;
}
