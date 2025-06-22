#include "monty.h"

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file (unused)
 *
 * Description: The top element of the stack becomes the last one,
 *              and the second element becomes the first one.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *s, temp;

    /** If stack pointer is NULL, do nothing */
    if (!stack)
        return;

    (void)line_number;

    s = *stack;

    /** If stack is empty or has only one element, do nothing */
    if (!s || !s->next)
    {
        return;
    }

    /** Move s to the last node */
    while (s->next)
        s = s->next;

    /** Save the second node of the stack */
    temp.next = (*stack)->next;

    /** Link last node to first node */
    s->next = (*stack);
    (*stack)->prev = s;

    /** First node becomes last (next is NULL) */
    (*stack)->next = NULL;

    /** Move stack pointer to new top */
    (*stack) = temp.next;
}
