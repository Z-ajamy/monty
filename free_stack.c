#include "monty.h"

/**
 * free_stack - Frees the entire stack
 * @top: Double pointer to the top of the stack
 *
 * Description: Iterates through the stack and frees each node.
 */
void free_stack(stack_t **top)
{
    stack_t *t;

    /** Iterate while stack is not empty */
    while (top && *top)
    {
        t = *top;               /** Save current top */
        *top = (*top)->next;    /** Move to the next node */
        free(t);                /** Free the old top node */
    }
}
