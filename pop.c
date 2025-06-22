#include "monty.h"

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *s;

    if (!stack)
        return;
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        g_vars.status = 1;
        return;
    }
    s = *stack;
    *stack = (*stack)->next;
    if (*stack)
    {
        (*stack)->prev = NULL;
    }
    
    free(s);
}
