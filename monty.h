#ifndef MONTY_H
#define MONTY_H

/** Enable GNU extensions for getline() */
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer stored in the node
 * @prev: Points to the previous element of the stack (or queue)
 * @next: Points to the next element of the stack (or queue)
 *
 * Description: Node structure for stack/queue
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: The opcode (command string)
 * @f: Function to handle the opcode
 *
 * Description: Opcode-function pair for Monty interpreter
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct command_line - Represents a parsed line from the Monty file
 * @line_number: The line number in the file
 * @command: The command string (opcode)
 * @arg: The argument string (if any)
 *
 * Description: Struct used to hold a parsed command and its argument
 */
typedef struct command_line
{
	int line_number;
	char *command;
	char *arg;
} command_t;

/**
 * struct global_vars_s - Struct for holding global variables
 * @arg: Integer argument value (if needed)
 * @status: Program status (success/failure)
 *
 * Description: Global variables used by the Monty interpreter
 */
typedef struct global_vars_s
{
	char *arg;
	int status;
} global_vars_t;

/** Extern declaration of the global variables */
extern global_vars_t g_vars;

/** Function Prototypes */

/** Parses a line into command and argument */
command_t *parsing(char *line, int line_number);

/** Executes a parsed command */
int executor(stack_t **top, command_t *command_ptr, unsigned int linenum);

/** Frees the entire stack */
void free_stack(stack_t **top);

/** Pushes a new value onto the stack */
void push(stack_t **top, unsigned int line_number);

/** Prints all values on the stack */
void pall(stack_t **stack, unsigned int line_number);

int isdigite(char *str);

void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);



#endif /* MONTY_H */
