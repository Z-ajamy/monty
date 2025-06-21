#include"monty.h"

void free_stack(stack_t **top)
{
    stack_t *t;

    while (top && *top)
    {
        t = *top;
        *top = (*top)->next;
        free(t);
    }
}
