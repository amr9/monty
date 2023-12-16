#include "monty.h"

/**
 * OpenFile - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void OpenFile(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		Error(2, file_name);

	ReadFile(fd);
	fclose(fd);
}


/**
 * ReadFile - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void ReadFile(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = ParseLine(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * ParseLine - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int ParseLine(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		Error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	FindFunc(opcode, value, line_number, format);
	return (format);
}

/**
 * FindFunc - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void FindFunc(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", AddStack},
		{"pall", PrintStack},
		{"pint", PrintTop},
		{"pop", PopTop},
		{"nop", Nop},
		{"swap", SwapNodes},
		{"add", AddNodes},
		{"sub", SubNodes},
		{"div", DivNodes},
		{"mul", MulNodes},
		{"mod", ModNodes},
		{"pchar", PrintChar},
		{"pstr", PrintStr},
		{"rotl", RotateBottom},
		{"rotr", RotateTop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			CallFun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		Error(3, ln, opcode);
}


/**
 * CallFun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void CallFun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int x;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			Error(5, ln);
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
				Error(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
