#include "monty.h"

/**
 * parsing - Parses a line into command and argument
 * @line: The input line
 * @line_number: Line number in the Monty file
 *
 * Return: Pointer to command_t struct or NULL on failure
 */
command_t *parsing(char *line, int line_number)
{
    char *command, *arg;
    command_t *command_ptr;

    /** Allocate memory for command struct */
    command_ptr = (command_t *)malloc(sizeof(command_t));
    if (!command_ptr)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }

    /** Initialize fields */
    command_ptr->command = NULL;
    command_ptr->arg = NULL;
    command_ptr->line_number = line_number;

    /** Extract the first token (command) */
    command = strtok(line, " \t\n");

    /** If empty line or comment line, return empty struct */
    if (!command || command[0] == '#')
    {
        return (command_ptr);
    }

    /** Allocate memory for the command string */
    command_ptr->command = (char *)malloc(strlen(command) + 1);
    if (!command_ptr->command)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free(command_ptr);
        return (NULL);
    }

    /** Copy the command string */
    strcpy(command_ptr->command, command);

    /** Extract the second token (argument) */
    arg = strtok(NULL, " \t\n");

    /** If argument exists and is not a comment */
    if (arg && arg[0] != '#')
    {
        /** Allocate memory for argument string */
        command_ptr->arg = (char *)malloc(strlen(arg) + 1);
        if (!command_ptr->arg)
        {
            fprintf(stderr, "Error: malloc failed\n");
            free(command_ptr->command);
            free(command_ptr);
            return (NULL);
        }

        /** Copy the argument string */
        strcpy(command_ptr->arg, arg);
    }

    /** Return the filled command struct */
    return (command_ptr);
}
