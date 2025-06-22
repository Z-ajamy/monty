#include "monty.h"

/**
 * isdigite - Checks if a string represents a valid integer
 * @str: The string to check
 *
 * Return: 1 if valid integer, 0 otherwise
 */
int isdigite(char *str)
{
    int i = 0;

    /** Null string is not a valid integer */
    if (!str)
        return (0);

    /** Loop through each character */
    while (str[i] != '\0')
    {
        /** Allow negative sign at the first character */
        if (i == 0 && str[0] == '-')
        {
            i++;
            continue;
        }

        /** If character is not between '0' and '9' */
        if (str[i] > '9' || str[i] < '0')
            return (0);

        i++;
    }

    /** If passed all checks, it's a valid integer */
    return (1);
}

/**
 * executor - Executes a parsed Monty command
 * @top: Double pointer to the top of the stack
 * @command_ptr: Parsed command and argument
 * @linenum: Current line number in the Monty file
 *
 * Return: 1 on success, 0 on failure
 */
int executor(stack_t **top, command_t *command_ptr, unsigned int linenum)
{
    int i = 0, flag = 1;

    /** Array of opcodes that require an argument */
    instruction_t fun_with_arg[2] = {
        {"push", push},
        {NULL, NULL}
    };

    /** Array of opcodes that do not require an argument */
    instruction_t fun_no_arg[2] = {
        {"pall", pall},
        {NULL, NULL}
    };

    /** Validate the argument (if any) */
    if (!isdigite(command_ptr->arg))
    {
        free(command_ptr->arg);
        g_vars.arg = NULL;
    }
    else
    {
        g_vars.arg = (char *)malloc(sizeof(char) * (strlen(command_ptr->arg) + 1));
        if (!g_vars.arg)
        {
            fprintf(stderr, "Error: malloc failed\n");
            return (0);
        }
        strcpy(g_vars.arg, command_ptr->arg);
    }

    /** Search for matching opcode in no-argument list */
    while (fun_no_arg[i].opcode)
    {
        if (!strcmp(fun_no_arg[i].opcode, command_ptr->command))
        {
            fun_no_arg[i].f(top, linenum);
            flag = 0;
            break;
        }
        i++;
    }

    i = 0;

    /** Search for matching opcode in argument list */
    while (fun_with_arg[i].opcode && flag)
    {
        if (!strcmp(fun_with_arg[i].opcode, command_ptr->command))
        {
            fun_with_arg[i].f(top, linenum);
            flag = 0;
            break;
        }
        i++;
    }

    /** If unknown instruction */
    if (flag)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n",
                linenum, command_ptr->command);
        return (0);
    }

    /** If global status indicates error */
    if (g_vars.status)
    {
        return (0);
    }

    return (1);
}
