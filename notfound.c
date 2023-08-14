#include "holberton.h"

/**
 * print_command_not_found - Prints an error message when a command is not found.
 * @args: Array of arguments typed by the user.
 * @counter: Number of times the shell has been executed.
 * Return: Exit status.
 */
int print_command_not_found(char **args, int counter)
{
	const char *shell_name_interactive = "simpl3-sh";
	const char *shell_name_non_interactive = "./simpl3-sh";

	if (isatty(STDIN_FILENO))
		write(2, shell_name_interactive, 10);
	else
		write(2, shell_name_non_interactive, 13);
	write(2, ": ", 2);
	print_numbers(counter);
	write(2, ": ", 2);
	write(2, args[0], _strlen(args[0]));
	write(2, ": not found\n", 12);
	return (127);
}
