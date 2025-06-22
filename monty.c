#include"monty.h"

global_vars_t g_vars = {0, 0};

int main(int argc, char *argv[])
{
    unsigned int linenum = 0, flag;
    ssize_t n;
    size_t i = 0;
    char *line = NULL;
    command_t *command_ptr;
    stack_t *stack = NULL;
    FILE *fp;


    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit (EXIT_FAILURE);
    }
    
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit (EXIT_FAILURE);
    }
    
    while (1)
    {
        linenum++;
        
        n = getline(&line, &i, fp);
        if (n == -1)
            break;
        
        command_ptr = parsing(line, linenum);
        if (!command_ptr)
        {
            free_stack(&stack);
            free(line);
            fclose(fp);
            exit (EXIT_FAILURE);
        }
        if (!command_ptr->command)
        {
            free(command_ptr);
            continue;
        }


        flag = executor(&stack, command_ptr, linenum);
        free(command_ptr->command);
        free(command_ptr->arg);
        free(command_ptr);

        if (!flag)
            break;
    }

    free_stack(&stack);
    free(line);
    fclose(fp);
    if (!flag)
        exit (EXIT_FAILURE);
    return 0;
}
