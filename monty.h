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
 * @arg: String argument value (if needed)
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

/**
 * parsing - Parses a line into command and argument
 */
command_t *parsing(char *line, int line_number);

/**
 * executor - Executes a parsed command
 */
int executor(stack_t **top, command_t *command_ptr, unsigned int linenum);

/**
 * free_stack - Frees the entire stack
 */
void free_stack(stack_t **top);

/**
 * push - Pushes a new value onto the stack
 */
void push(stack_t **top, unsigned int line_number);

/**
 * pall - Prints all values on the stack
 */
void pall(stack_t **stack, unsigned int line_number);

/**
 * isdigite - Checks if a string is a valid integer
 */
int isdigite(char *str);

/**
 * pint - Prints the value at the top of the stack
 */
void pint(stack_t **stack, unsigned int line_number);

/**
 * pop - Removes the top element of the stack
 */
void pop(stack_t **stack, unsigned int line_number);

/**
 * swap - Swaps the top two elements of the stack
 */
void swap(stack_t **stack, unsigned int line_number);

/**
 * add - Adds the top two elements of the stack
 */
void add(stack_t **stack, unsigned int line_number);

/**
 * sub - Subtracts the top element from the second element of the stack
 */
void sub(stack_t **stack, unsigned int line_number);

/**
 * _div - Divides the second element by the top element of the stack
 */
void _div(stack_t **stack, unsigned int line_number);

/**
 * mul - Multiplies the top two elements of the stack
 */
void mul(stack_t **stack, unsigned int line_number);

/**
 * mod - Computes the rest of the division of the second element by the top
 */
void mod(stack_t **stack, unsigned int line_number);

/**
 * pchar - Prints the char at the top of the stack
 */
void pchar(stack_t **stack, unsigned int line_number);

/**
 * pstr - Prints the string starting at the top of the stack
 */
void pstr(stack_t **stack, unsigned int line_number);

/**
 * rotl - Rotates the stack to the top
 */
void rotl(stack_t **stack, unsigned int line_number);

/**
 * rotr - Rotates the stack to the bottom
 */
void rotr(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
