#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */
void push(stack_t **stack, char *arg, unsigned int line_number);
{
    char *arg = get_op_arg();
    int value = atoi(arg);

    if (value == 0 && strcmp(arg, "0") != 0)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    new_node->next = *stack;
    *stack = new_node;
}