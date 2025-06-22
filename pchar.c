#include "monty.h"

void pchar(stack_t **stack, unsigned int line_number)
{
    int temp;
    if (!stack)
        return;
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        g_vars.status = 1;
        return;
    }

    temp = (*stack)->n;
    if (temp > 126 || temp < 32)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        g_vars.status = 1;
        return;
    }
    printf("%c", temp);
}
