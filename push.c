#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @arg: the argument to push onto the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */
void push(stack_t **stack, char *arg, unsigned int line_number)
{
stack_t *new_node;
(void)line_number;
(void)arg;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = atoi(arg);
new_node->prev = NULL;

if (*stack != NULL)
{
new_node->next = *stack;
(*stack)->prev = new_node;
}
else
{
new_node->next = NULL;
}

*stack = new_node;
}
