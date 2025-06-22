#include "monty.h"

/**
 * pint - Prints the value at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: If the stack is empty, prints an error message.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    /** If stack pointer is NULL, do nothing */
    if (!stack)
        return;

    /** If stack is empty, print error */
    if (!(*stack))
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        g_vars.status = 1;
        return;
    }

    /** Print value at the top of the stack */
    printf("%d\n", (*stack)->n);
}
