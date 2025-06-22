#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from the second top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: The result is stored in the second element from the top,
 *              and the top element is removed.
 *              If the stack contains less than two elements, prints an error.
 */
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *s;
    int temp;

    /** If stack pointer is NULL, do nothing */
    if (!stack)
        return;

    /** If stack contains less than two elements, print error */
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        g_vars.status = 1;
        return;
    }

    /** Save value of the top element */
    s = *stack;
    temp = s->n;

    /** Move stack pointer to the next element */
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    /** Subtract top element from new top */
    (*stack)->n = (*stack)->n - temp;

    /** Free old top element */
    free(s);
}
