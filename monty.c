#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char opcode[100];
    int value;
    unsigned int line_number = 0;
    /*     // Check for valid number of arguments
     */
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack = NULL;
   

/*     // Read and interpret the bytecode file line by line
 */    while (fgets(opcode, sizeof(opcode), file) != NULL)
    {
        line_number++;

/*         // Parse opcode and value (if any)
 */        if (sscanf(opcode, "push %d", &value) == 1)
        {
            push(&stack, value);
        }
        else if (strcmp(opcode, "pall\n") == 0)
        {
            pall(&stack);
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s", line_number, opcode);
            return EXIT_FAILURE;
        }
    }

    fclose(file);

    return EXIT_SUCCESS;
}
