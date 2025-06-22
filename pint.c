#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack)
        return;
    if (!(*stack))
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        g_vars.status = 1;
        return;
    }
    
    printf("%d\n", (*stack)->n);
}
