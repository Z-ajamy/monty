#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *s;
    int temp;

    if (!stack)
        return;
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        g_vars.status = 1;
        return;
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
