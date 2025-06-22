#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack with the top element
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: The result is stored in the second element from the top,
 *              and the top element is removed.
 */
void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *s;
    int temp;

    /** If stack is NULL, do nothing */
    if (!stack)
        return;

    /** If stack has fewer than 2 elements, print error */
    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        g_vars.status = 1;
        return;
    }

    /** Store current top element */
    s = *stack;
    temp = s->n;

    /** Move stack pointer to the second element */
    *stack = (*stack)->next;

    /** Update new top element with multiplication result */
    (*stack)->prev = NULL;
    (*stack)->n = (*stack)->n * temp;

    /** Free old top node */
    free(s);
}
