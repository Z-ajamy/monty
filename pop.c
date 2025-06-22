#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: If the stack is empty, prints an error message.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *s;

    /** If stack pointer is NULL, do nothing */
    if (!stack)
        return;

    /** If stack is empty, print error */
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        g_vars.status = 1;
        return;
    }

    /** Save current top node */
    s = *stack;

    /** Move stack pointer to the next node */
    *stack = (*stack)->next;

    /** If new top exists, update its prev pointer */
    if (*stack)
    {
        (*stack)->prev = NULL;
    }

    /** Free old top node */
    free(s);
}
