#include "monty.h"
int main(int argc, char *argv[])
{
stack_t *stack = NULL;
char *line = NULL, *token;
size_t len = 0, i;
unsigned int line_number = 1;
FILE *fp;
instruction_t opcodes[] = {
{"pall", pall},
{"push", push},
{NULL, NULL}};
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}
fp = fopen(argv[1], "r");
if (fp == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}
while (fgets(line, len, fp) != NULL)
{
token = strtok(line, " \n\t\r");
if (token == NULL || token[0] == '#')
{
line_number++;
continue;
}
for (i = 0; opcodes[i].opcode != NULL; i++)
{
if (strcmp(token, opcodes[i].opcode) == 0)
{
token = strtok(NULL, " \n\t\r");
opcodes[i].f(&stack, token, line_number);
break;
}}
if (opcodes[i].opcode == NULL)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
return (EXIT_FAILURE);
}
line_number++;
}
free(line);
fclose(fp);
return (EXIT_SUCCESS);
}
