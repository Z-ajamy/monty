#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *ptr;
    (void)line_number;
    if (!stack)
        return;
    ptr = *stack;

    while (ptr)
    {
        printf("%d\n", ptr->n);
        ptr = ptr->next;
    }
    
}
