#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef struct command_line
{
        int line_number;
        char *command;
        char *arg;
} command_t;


typedef struct global_vars_s
{
	int arg;
	int status;
} global_vars_t;
extern global_vars_t g_vars;

command_t *parsing(char *line, int line_number);
int executor(stack_t **top, command_t *command_ptr, unsigned int linenum);
void free_stack(stack_t **top);
void push(stack_t **top, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

#endif
