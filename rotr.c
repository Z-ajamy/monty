#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file (unused)
 *
 * Description: The last element of the stack becomes the first one,
 *              all other elements move one position down.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *s;

    /** If stack pointer is NULL, empty, or has only one node, do nothing */
    if (!stack || !*stack || !(*stack)->next)
        return;

    (void)line_number;

    s = *stack;

    /** Move s to the last node */
    while (s->next)
        s = s->next;

    /** Unlink last node from previous */
    if (s->prev)
        s->prev->next = NULL;

    /** Move last node to the top of stack */
    s->prev = NULL;
    s->next = (*stack);

    /** Update old top's prev pointer */
    (*stack)->prev = s;

    /** Update stack pointer to new top */
    *stack = s;
}
