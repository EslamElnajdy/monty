#include "monty.h"
/**
 * f_push - to add new node or queue
 * @head: pointer to the stack.
 * @counter: number of line.
*/
void f_push(stack_t **head, unsigned int counter)
{
	int i = 0, flag = 0, n;

	if (info_global.arg)
	{
		if (info_global.arg[0] == '-')
			i++;
		for (; info_global.arg[i] != '\0'; i++)
		{
			if (info_global.arg[i] > 57 || info_global.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(info_global.file);
			free(info_global.buffer);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(info_global.file);
		free(info_global.buffer);
		exit(EXIT_FAILURE);
	}
	n = atoi(info_global.arg);
	if (info_global.lifi == 0)
	{
		addnode(head, n);
	}
	else
		addqueue(head, n);
}
