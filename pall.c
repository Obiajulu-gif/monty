#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */
void pall(stack_t **stack, char *arg, unsigned int line_number)
{
    stack_t *current = *stack;
    if (current == NULL)
    {
        return;
    }

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}