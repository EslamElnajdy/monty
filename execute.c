#include "monty.h"
/**
 * execute - execute the operation
 * @content: content.
 * @stack: pointer to the stack
 * @count: number of line
 * @file: pointer to file
 * Return: 1
*/
int execute(char *content, stack_t **stack, int count, FILE *file)
{
	instruction_t op_st[] = {
		{"push", f_push},
		{"pall", f_pall},
		{"pint", f_pint},
		{"pop", f_pop},
		{"swap", f_swap},
		{"add", f_add},
		{"nop", f_nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	info_global.arg = strtok(NULL, " \n\t");

	while (op_st[i].opcode && op)
	{
		if (strcmp(op_st[i].opcode, op) == 0)
		{
			op_st[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && op_st[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
