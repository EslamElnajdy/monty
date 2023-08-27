#include "monty.h"
/**
 * f_swap - swaps the top two elements of the stack.
 * @head: pointer to the stack
 * @line_number: line number
*/
void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *p;
	int count = 0, temp;

	p = *head;
	while (p)
	{
		p = p->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(info_global.file);
		free(info_global.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	temp = p->n;
	p->n = p->next->n;
	p->next->n = temp;
}
