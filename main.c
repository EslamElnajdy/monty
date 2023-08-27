#include "monty.h"
global_info info_global = {NULL, NULL, NULL, 0};

/**
 * main - code interpreter.
 * @argc: number of args.
 * @argv: the args.
 * Return: 0
*/

int main(int argc, char *argv[])
{
	FILE *file;
	ssize_t line = 1;
	char *buffer;
	size_t size = 0;
	unsigned int count = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	info_global.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		buffer = NULL;
		line = getline(&buffer, &size, file);
		info_global.buffer = buffer;
		count++;
		if (line > 0)
		{
			execute(buffer, &stack, count, file);
		}
		free(buffer);
	}
	free_stack(stack);
	fclose(file);

	return (0);
}
