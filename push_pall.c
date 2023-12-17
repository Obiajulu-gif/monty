#include "monty.h"


void push(int value)
{
if (top == STACK_SIZE - 1)
{
fprintf(stderr, "Stack Overflow\n");
exit(EXIT_FAILURE);
}
stack[++top] = value;
}

void pall(void)
{
int i;
for (i = top; i >= 0; i--)
{
printf("%d\n", stack[i]);
}
}
