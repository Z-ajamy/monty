#include "monty.h"

void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *s, temp;
    if (!stack)
        return;
    (void)line_number;


    s = *stack;
    while (s->next)
        s = s->next;
    
    temp.next = (*stack)->next;

    s->next = (*stack);
    (*stack)->prev = s;
    (*stack)->next = NULL;

    
    (*stack)= temp.next;
}
