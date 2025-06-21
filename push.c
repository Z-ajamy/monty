#include"monty.h"

void push(stack_t **top, unsigned int line_number)
{
    stack_t *new = NULL;
    stack_t *ptr = NULL;

    (void)line_number;
    if (!top)
        return;
    ptr = *top;
    new = (stack_t *)malloc(sizeof(stack_t));
    if (!new)
        {
            fprintf(stderr, "Error: malloc failed\n");
            g_vars.status = 1;
            return;
        }

    new->n = g_vars.arg;
    new->prev = NULL;
    new->next = ptr;
    if (ptr)
    {
        ptr->prev = new;
    }
    *top = new;
}
