#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: If the stack contains less than two elements,
 *              prints an error message.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    /** If stack pointer is NULL, do nothing */
    if (!stack)
        return;

    /** If stack contains less than two elements, print error */
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        g_vars.status = 1;
        return;
    }

    /** Swap the values of the first two elements */
    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
