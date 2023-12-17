#include  "monty.h"
int main(int argc, char *argv[])
{
FILE *file;
char opcode[100];
int arg;
int line_number = 1;
if (argc != 2)
{
fprintf(stderr, "Usage: %s file\n", argv[0]);
return (EXIT_FAILURE);
}
file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error opening file\n");
return (EXIT_FAILURE);
}
while (fscanf(file, "%s", opcode) != EOF)
{
if (strcmp(opcode, "push") == 0)
{
if (fscanf(file, "%d", &arg) != 1)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}
push(arg);
}
else if (strcmp(opcode, "pall") == 0)
{
pall();
}
else
{
fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
return (EXIT_FAILURE);
}
line_number++;
}
fclose(file);
return (EXIT_SUCCESS);
}
