#include"monty.h"


int isdigite(char *str)
{
    int i = 0;
    if (!str)
        return 0;
    
    while (str[i] != '\0')
    {
        if (i == 0 && str[0] == '-')
        {
            i++;
            continue;
        }
            
        if (str[i] > '9' || str[i] < '0')
            return 0;
        i++;
    }
    return 1;
}

int executor(stack_t **top, command_t *command_ptr, unsigned int linenum)
{
    int i = 0, flag = 1;
    instruction_t arr[3] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    if(!isdigite(command_ptr->arg))
    {
        command_ptr->arg = NULL;
    }
    else
    {
        g_vars.arg = atoi(command_ptr->arg);
    }
    while (arr[i].opcode)
    {
        if (!strcmp(arr[i].opcode, command_ptr->command))
        {
            arr[i].f(top, linenum);
            flag = 0;
            break;
        }
        i++;
    }
    if (flag)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", linenum, command_ptr->command);
        return 0;
    }
    if (g_vars.status)
    {
        return 0;
    }
    return 1;
}
