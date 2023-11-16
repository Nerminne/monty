#include "monty.h"
/**
 * stack_free: free all nodes
 * @stack: pointer to linked list
 * Return: nothing
 */
void stack_free(stack_t *stack)
{
	stack_t *temp = stack;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
