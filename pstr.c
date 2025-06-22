#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file (unused)
 *
 * Description: Prints the characters of the stack from top until:
 *              - the stack ends
 *              - a value is not in printable ASCII range
 *              - a value is 0
 *              Then prints a newline.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    int temp;

    (void)line_number;

    /** If stack pointer is NULL, do nothing */
    if (!stack)
        return;

    /** If stack is empty, just print newline */
    if (!*stack)
    {
        printf("\n");
        return;
    }

    /** Get value from top of stack */
    temp = (*stack)->n;

    /** If value is not printable ASCII, terminate string with newline */
    if (temp > 126 || temp < 32)
    {
        printf("\n");
        return;
    }

    /** Print the character */
    printf("%c", temp);

    /** Recursively call pstr on the next element */
    pstr(&((*stack)->next), line_number);
}
