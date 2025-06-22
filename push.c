#include "monty.h"

/**
 * push - Pushes an element onto the stack
 * @top: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file (unused here)
 *
 * Description: Creates a new node and adds it to the top of the stack.
 */
void push(stack_t **top, unsigned int line_number)
{
    stack_t *new = NULL;
    stack_t *ptr = NULL;

    /** Silence unused variable warning */
    (void)line_number;

    /** If stack is invalid, do nothing */
    if (!top)
        return;

    ptr = *top;

    /** Allocate memory for the new node */
    new = (stack_t *)malloc(sizeof(stack_t));
    if (!new)
    {
        /** Print malloc error */
        fprintf(stderr, "Error: malloc failed\n");
        g_vars.status = 1;
        return;
    }

    /** Initialize the new node */
    new->n = g_vars.arg;
    new->prev = NULL;
    new->next = ptr;

    /** If stack is not empty, update the previous pointer of old top */
    if (ptr)
    {
        ptr->prev = new;
    }

    /** Set the new node as the top of the stack */
    *top = new;
}
