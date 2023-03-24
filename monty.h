#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define Buffsize 30

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct globals - global varialbles
 * @file: file name
 * @buff: Getline buffer
 * @tmp: Getline counter
 * @dict: instruction dictionary
 * @head: pointer to list
 * @line_number: Stores file current line
 * @MODE: Program configuration stack or queue
 */
typedef struct globals
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line;
	int MODE;
} globals;


extern globals global;

/* util functions */
int init_globals(globals *global);
instruction_t *map_funcs();
int get_funct(globals *global, char *opcode);
void free_all(void);
int _isdigit(char *string);

/* operation functions */
void pall(stack_t **stack, unsigned int line);
void push(stack_t **stack, unsigned int line);
void pint(stack_t **stack, unsigned int line);
void pop(stack_t **stack, unsigned int line);

void swap(stack_t **stack, unsigned int line);
void add(stack_t **stack, unsigned int line);
void sub(stack_t **stack, unsigned int line);
void divi(stack_t **stack, unsigned int line);

void mul(stack_t **stack, unsigned int line);
void mod(stack_t **stack, unsigned int line);
void pchar(stack_t **stack, unsigned int line);
void pstr(stack_t **stack, unsigned int line);

void rotl(stack_t **stack, unsigned int line);
void rotr(stack_t **stack, unsigned int line);
void stack(stack_t **stack, unsigned int line);
void queue(stack_t **stack, unsigned int line);


#endif /* _MAIN_H_ */
