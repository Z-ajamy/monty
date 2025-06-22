#include "monty.h"

void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *s;
    int temp;

    if (!stack)
        return;
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        g_vars.status = 1;
        return;
    }

    
    s = *stack;
    temp = s->n;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    (*stack)->n = (*stack)->n - temp;

    free(s);
}
