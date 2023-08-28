#include "monty.h"
/**
 * f_div - divides the second top element of the stack by the top element of the stack.
 * @head: pointer to the stack
 * @line_number: line number
*/
void f_div(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		fclose(info_global.file);
		free(info_global.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	temp = p->n;
	if (temp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(info_global.file);
		free(info_global.buffer);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	p->next->n /= temp;
	*head = (*head)->next;
	free(p);
}
