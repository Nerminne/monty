#include "monty.h"
/**
 * pchar - print char
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int charac;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		data = -500;
		return;
	}
	charac = (*stack)->n;
	if (charac >= 0 && charac <= 127)
		printf("%c\n", charac);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		data = -500;
		return;
	}
}
/**
 * pstr - print string
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int charac;

	(void)line_number;
	if (stack)
	{
		while (temp)
		{
			charac = temp->n;
			if (charac >= 0 && charac <= 127)
			{
				if (charac == 0)
					break;
				printf("%c", charac);
			}
			else
			{
				data = -500;
				return;
			}
			temp = temp->next;
		}
	}
	printf("\n");
}
/**
 * rotl - rotate the stack to the top
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *s_last, *temp;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	s_last = *stack;
	temp = *stack;
	while (s_last->next)
		s_last = s_last->next;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	temp->prev = s_last;
	s_last->next = temp;
}
/**
 * rotr - rotate the stack to the bot
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *s_last;

	(void) line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	s_last = *stack;
	while (s_last->next)
		s_last = s_last->next;
	s_last->prev->next = NULL;
	s_last->prev = NULL;
	(*stack)->prev = s_last;
	s_last->next = *stack;
	*stack = s_last;
}
/**
 * _div - divided last two digit
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		data = -500;
		return;
	}
	if ((*stack)->n == 0 || (*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		data = -500;
		return;
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
