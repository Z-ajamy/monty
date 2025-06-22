#include "monty.h"

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *s;
    if (!stack || !*stack || !(*stack)->next)
        return;
    (void)line_number;

    s = *stack;
    while (s->next)
        s = s->next;

    if (s->prev)
        s->prev->next = NULL;

    s->prev = NULL;
    s->next = (*stack);
    (*stack)->prev = s;
    *stack = s;
}
