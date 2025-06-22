#include "monty.h"

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file (unused here)
 *
 * Description: Prints each element in the stack from top to bottom.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr;

    /** Silence unused variable warning */
    (void)line_number;

    /** If stack pointer is NULL, do nothing */
    if (!stack)
        return;

    ptr = *stack;

    /** Traverse the stack and print each value */
    while (ptr)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
}
