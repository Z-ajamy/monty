#include "monty.h"

/** Initialize global variables */
global_vars_t g_vars = {0, 0};

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
    unsigned int linenum = 0, flag;
    ssize_t n;
    size_t i = 0;
    char *line = NULL;
    command_t *command_ptr;
    stack_t *stack = NULL;
    FILE *fp;

    /** Check for correct number of arguments */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /** Open the Monty bytecode file */
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /** Read and process each line */
    while (1)
    {
        linenum++;

        /** Read next line from file */
        n = getline(&line, &i, fp);
        if (n == -1)
            break;

        /** Parse the line */
        command_ptr = parsing(line, linenum);
        if (!command_ptr)
        {
            free_stack(&stack);
            free(line);
            fclose(fp);
            exit(EXIT_FAILURE);
        }

        /** Skip empty lines or comment lines */
        if (!command_ptr->command)
        {
            free(command_ptr);
            continue;
        }

        /** Execute the parsed command */
        flag = executor(&stack, command_ptr, linenum);

        /** Free allocated memory for command */
        free(command_ptr->command);
        free(command_ptr->arg);
        free(command_ptr);

        /** If execution failed, stop */
        if (!flag)
            break;
    }

    /** Clean up and exit */
    free_stack(&stack);
    free(line);
    fclose(fp);

    if (!flag)
        exit(EXIT_FAILURE);

    return (0);
}
