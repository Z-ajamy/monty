#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack
 * @stack: Double pointer to the top of the stack
 * @line_number: Current line number in the Monty file
 *
 * Description: Prints the character value of the top node.
 *              If stack is empty or value is out of printable ASCII range,
 *              prints an error.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    int temp;

    /** If stack pointer is NULL, do nothing */
    if (!stack)
        return;

    /** If stack is empty, print error */
    if (!*stack)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        g_vars.status = 1;
        return;
    }

    /** Get value from top of stack */
    temp = (*stack)->n;

    /** If value is not printable ASCII, print error */
    if (temp > 126 || temp < 32)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        g_vars.status = 1;
        return;
    }

    /** Print character */
    printf("%c\n", temp);
}
