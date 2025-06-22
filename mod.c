#include "monty.h"

void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *s;
    int temp;

    if (!stack)
        return;
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        g_vars.status = 1;
        return;
    }

    
    s = *stack;
    temp = s->n;

    if (temp == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        g_vars.status = 1;
        return;
    }

    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    (*stack)->n = (*stack)->n % temp;

    free(s);
}
