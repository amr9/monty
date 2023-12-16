#include "monty.h"

/**
 * Error - Prints appropiate error messages determined by their error code.
 * @error_number: The error codes are :
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void Error(int error_number, ...)
{
	va_list ag;
	char *ov;
	int Lnumber;

	va_start(ag, error_number);
	switch (error_number)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			Lnumber = va_arg(ag, int);
			ov = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", Lnumber, ov);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * ErrorTwo - handles errors.
 * @error_number: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void ErrorTwo(int error_number, ...)
{
	va_list ag;
	char *ov;
	int Lnumber;

	va_start(ag, error_number);
	switch (error_number)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(ag, int));
			break;
		case 8:
			Lnumber = va_arg(ag, unsigned int);
			ov = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", Lnumber, ov);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * StringError - handles errors.
 * @error_number: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void StringError(int error_number, ...)
{
	va_list ag;
	int Lnumber;

	va_start(ag, error_number);
	Lnumber = va_arg(ag, int);
	switch (error_number)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", Lnumber);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", Lnumber);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
