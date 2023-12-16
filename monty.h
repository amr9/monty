#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void OpenFile(char *file_name);
void ReadFile(FILE *);
int ParseLine(char *buffer, int line_number, int format);
int LenChars(FILE *);
void FindFunc(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void PrintStack(stack_t **, unsigned int);
void AddStack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void CallFun(op_func, char *, char *, int, int);

void PrintTop(stack_t **, unsigned int);
void PopTop(stack_t **, unsigned int);
void Nop(stack_t **, unsigned int);
void SwapNodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void AddNodes(stack_t **, unsigned int);
void SubNodes(stack_t **, unsigned int);
void DivNodes(stack_t **, unsigned int);
void MulNodes(stack_t **, unsigned int);
void ModNodes(stack_t **, unsigned int);

/*String operations*/
void PrintChar(stack_t **, unsigned int);
void PrintStr(stack_t **, unsigned int);
void RotateBottom(stack_t **, unsigned int);
void RotateTop(stack_t **, unsigned int);
/*Error hanlding*/
void Error(int error_number, ...);
void ErrorTwo(int error_number, ...);
void StringError(int error_number, ...);


#endif
