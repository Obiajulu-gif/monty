#include  "monty.h"



int main() {
    Stack stack;
    stack.top = 0;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    pall(&stack);

    return 0;
}