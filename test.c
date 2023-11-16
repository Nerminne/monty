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
	int errorr, n_error;
	
	data = 0;
	ptr = fopen(file_name, "r");
	if (ptr == NULL)
		error(-1, file_name, NULL);
	
	for (line_num = 1; getline(&lineptr, &n, ptr) != -1; line_num++)
	{
		if (lineptr == NULL)
			error(-2, file_name, NULL);
		if (lineptr[0] == '#' || strcmp(lineptr, "\n") == 0)
			continue;
		oper = strtok(lineptr, " \t\n");
		if (oper)
		{
			num = strtok(NULL, " \t\n");
			n_error = num_check(num);
		}
		free(lineptr);
		if (n_error)
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
 * @num: data
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
 * Return: 0 if string is number -1 if not
 */
int num_check(char *num)
{
	int i;

	for (i = 0; num[i]; i++)
	{
		if (num[i] == '-')
			continue;
		else if (num[i] < 48 || num[i] > 57)
			return (-1);
	}
	data = atoi(num);
	return (0);
}
