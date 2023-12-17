#include "monty.h"


/**
 * push - Pushes an element to the stack.
 * @stack: The stack.
 * @value: The value to push.
 */
void push(Stack *stack, int value) {
    if (stack->top == STACK_SIZE) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->stack[stack->top++] = value;
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: The stack.
 */
void pall(Stack *stack) {
    int i;
    for (i = stack->top - 1; i >= 0; i--) {
        printf("%d\n", stack->stack[i]);
    }
}
