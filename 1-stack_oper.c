#include "monty.h"
/**
 * push - push number to stack
 * @stack: pointer to linked list
 * Return: nothing
 */
void push(stack_t **stack)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		stack_free(*stack);
		error(-2, NULL, NULL);
	}
	new_node->n = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * pall - print all nodes
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		fprintf(stderr, "%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - print value of the top of stack
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		fprintf(stderr, "%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		data = -500;
		return;
	}
}
/**
 * pop - remove top node
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		if ((*stack)->next)
		{
			(*stack)->next->prev = NULL;
			*stack = (*stack)->next;
		}
		else
			*stack = NULL;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		data = -500;
		return;
	}
}
/**
  * nop - do nothing
  * @stack: pointer to linked list
  * @line_number: line number
  * Return: nothing
  */
void nop(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	(void)line_number;
}
