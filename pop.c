#include "monty.h"
/**
 * f_pop - remove the top item
 * @head: pointer to the stack
 * @line_number: line number
*/
void f_pop(stack_t **head, unsigned int line_number)
{
	stack_t *p;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(info_global.file);
		free(info_global.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	*head = p->next;
	free(p);
}
