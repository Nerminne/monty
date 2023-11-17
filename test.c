#include "monty.h"
/**
 * test_file - trying to open the file
 * @file_name: file name
 * Return: Noting
 */
void test_file(char *file_name)
{
	FILE *ptr;
	char lineptr[10000], *oper, *num;
	unsigned int line_num;
	stack_t *stack = NULL;
	int errorr, n_error = 0;

	ptr = fopen(file_name, "r");
	if (ptr == NULL)
		error(-1, file_name, NULL);

	for (line_num = 1; fgets(lineptr, sizeof(lineptr), ptr); line_num++)
	{
		if (lineptr == NULL)
			error(-2, file_name, NULL);
		if (lineptr[0] == '#' || strcmp(lineptr, "\n") == 0)
			continue;
		oper = strtok(lineptr, " \t\n");
		if (oper)
		{
			num = strtok(NULL, " \t\n");
			data = num_check(num, &n_error);
		}
		if (n_error && data == -1)
		{
			printf("L%u: usage: push integer\n", line_num);
			stack_free(stack);
			exit(EXIT_FAILURE);
		}
		errorr = executing(oper, &stack, line_num);
		if (errorr)
		{
			stack_free(stack);
			error(line_num, file_name, oper);
		}
	}
	fclose(ptr);
	stack_free(stack);
}
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
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
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

	if (num == NULL)
	{
		*n_error = -1;
		return (-1);
	}
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
