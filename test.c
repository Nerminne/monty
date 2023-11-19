#include "monty.h"
/**
 * test_file - trying to open the file
 * @file_name: file name
 * Return: Noting
 */
void test_file(char *file_name)
{
	FILE *ptr;
	char *lineptr = NULL, *oper, *num;
	size_t n = 0;
	unsigned int line_num;
	stack_t *stack = NULL;
	int errorr, n_error = 0;

	ptr = fopen(file_name, "r");
	if (ptr == NULL)
		error(-1, file_name, NULL);
	for (line_num = 1; getline(&lineptr, &n, ptr) != -1; line_num++)
	{
		if (lineptr[0] == '#' || strcmp(lineptr, "\n") == 0)
			continue;
		oper = strtok(lineptr, " \t\n");
		if (oper[0] == '#')
			continue;
		if (oper)
		{
			if (strcmp(oper, "push") == 0)
			{
				num = strtok(NULL, " \t\n");
				if (num)
					data = num_check(num, &n_error);
				if ((n_error && data == -1) || num == NULL)
				{
					stack_free(stack), free(lineptr), fclose(ptr);
					fprintf(stderr, "L%u: usage: push integer\n", line_num);
					exit(EXIT_FAILURE);
				}
				else
					push(&stack); }
			else
			{
				errorr = executing(oper, &stack, line_num);
				if (errorr || data == -500)
				{
					free(lineptr), stack_free(stack), fclose(ptr);
					exit(EXIT_FAILURE); }
			}
		}
	}
	fclose(ptr), free(lineptr), stack_free(stack), exit(EXIT_SUCCESS); }
/**
 * executing - executing the operation
 * @oper: operation to be executed
 * @stack: pointer to linked list
 * @line_num: line number
 * Return: 0 on success 1 on fail
 */
int executing(char *oper, stack_t **stack, unsigned int line_num)
{
	instruction_t oper_func[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"sub", sub},
		{"add", add},
		{"swap", swap},
		{"mod", mod},
		{"mul", mul},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"div", _div},
		{NULL, NULL}
	};
	int i;

	for (i = 0; oper_func[i].opcode; i++)
	{
		if (strcmp(oper, oper_func[i].opcode) == 0)
		{
			oper_func[i].f(stack, line_num);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, oper);
	return (1);
}
/**
 * num_check - check if string contain numbers
 * @num: string to be checked
 * @n_error: check error
 * Return: number
 */
int num_check(char *num, int *n_error)
{
	int i;

	for (i = 0; num[i]; i++)
	{
		if (num[i] == '-')
			continue;
		else if (num[i] < 48 || num[i] > 57)
		{
			*n_error = -1;
			return (-1);
		}
	}
	return (atoi(num));
}
