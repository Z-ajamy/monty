#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number)
{
    int temp;

    (void)line_number;
    if (!stack)
        return;
    if (!*stack)
    {
        printf("\n");
        return;
    }

    temp = (*stack)->n;
    if (temp > 126 || temp < 32)
    {
        printf("\n");
        return;
    }
    printf("%c", temp);
    pstr(&((*stack)->next), line_number);

}
