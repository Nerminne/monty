#include "monty.h"
/**
 * add - add last two num
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		data = -500;
		return;
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	sum = ptr->n + (*stack)->n;
	(*stack)->n = sum;
	free(ptr);
}
/**
 * sub - sub last two num
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int subb;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		data = -500;
		return;
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	subb = (*stack)->n - ptr->n;
	(*stack)->n = subb;
	free(ptr);
}
/**
 * swap - switch value of the top of stack
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		data = -500;
		return;
	}
	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}
/**
 * mul - multiply last two num
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int mull;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		data = -500;
		return;
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	mull = ptr->n * (*stack)->n;
	(*stack)->n = mull;
	free(ptr);
}
/**
 * mod - mod of last two num
 * @stack: pointer to linked list
 * @line_number: line number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int modd;
	stack_t *ptr;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		data = -500;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		data = -500;
		return;
	}
	ptr = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	modd = (*stack)->n % ptr->n;
	(*stack)->n = modd;
	free(ptr);
}
