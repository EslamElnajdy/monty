#include "monty.h"
/**
 * f_pint - print the top value
 * @head: pointer to stack
 * @counter: number of line
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if (head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", counter);
		fclose(info_global.file);
		free(info_global.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
