#include "monty.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: always 0 on success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		error(0, NULL, NULL);
	test_file(argv[1]);
	return (0);
}
/**
 * error - printing error on process fail
 * @line_num: line number where error was found
 * @file_name: name of file
 * @opercode: operation name
 * Return: Nothing
 */
void error(unsigned int line_num, char *file_name, char *opercode)
{
	(void)opercode;
	switch (line_num)
	{
		case 0:
		fprintf(stderr, "USAGE: monty file\n");
		break;
		case -1:
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		break;
		case -2:
		fprintf(stderr, "Error: malloc failed\n");
		break;
		default:
		break;
	}
	exit(EXIT_FAILURE);
}
