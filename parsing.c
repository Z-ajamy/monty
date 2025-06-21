#include "monty.h"

/**
 * parsing - Parses a line into command and argument
 * @line: The input line
 * @line_number: Line number in the Monty file
 *
 * Return: Pointer to command_l struct or NULL on failure
 */
command_l *parsing(char *line, int line_number)
{
    char *command, *arg;
    command_l *command_ptr;

    command_ptr = (command_l *)malloc(sizeof(command_l));
    if (!command_ptr)
    {
        fprintf(stderr, "Error: malloc failed\n");
        return (NULL);
    }

    command_ptr->command = NULL;
    command_ptr->arg = NULL;
    command_ptr->line_number = line_number;

    command = strtok(line, " \t\n");
    if (!command || command[0] == '#')
    {
        return (command_ptr);
    }

    command_ptr->command = (char *)malloc(strlen(command) + 1);
    if (!command_ptr->command)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free(command_ptr);
        return (NULL);
    }

    strcpy(command_ptr->command, command);

    arg = strtok(NULL, " \t\n");
    if (arg && arg[1] != '#')
    {
        command_ptr->arg = (char *)malloc(strlen(arg) + 1);
        if (!command_ptr->arg)
        {
            fprintf(stderr, "Error: malloc failed\n");
            free(command_ptr->command);
            free(command_ptr);
            return (NULL);
        }
        strcpy(command_ptr->arg, arg);
    }

    return (command_ptr);
}
