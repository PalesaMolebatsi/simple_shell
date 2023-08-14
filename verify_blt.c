#include "holberton.h"
/**
 * check_builtin - Verify if the input is a built-in command.
 * @args: Pointer to the array of arguments.
 * @exit_status: Current exit status.
 * Return: -1 if the command is not a built-in, 0 if it is.
 */
int check_builtin(char **args, int exit_status)
{
	char *builtins[] = {
		"exit",
		"env"
	};
	int i = 0;


	while (i < 2)
	{
		if (_strcmp(args[0], builtins[i]) == 0)
			break;
		i++;
	}
	if (i == 2)
		return (-1);


	if (_strcmp(builtins[i], "exit") == 0)
	{
		free(args[0]);
		exit(exit_status);
	}


	if (_strcmp(builtins[i], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		write(1, environ, 1000);
	}


	return (0);
}
