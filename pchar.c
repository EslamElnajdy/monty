#include "monty.h"
/**
 * f_pchar - prints the char at the top of the stack, followed by a new line.
 * @head: pointer to the stack
 * @line_number: line number
*/
void f_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *p;

	p = *head;
	if (p == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(info_global.file);
		free(info_global.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (p->n > 127 || p->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(info_global.file);
		free(info_global.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", p->n);
}
