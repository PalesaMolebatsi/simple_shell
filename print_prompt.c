#include "holberton.h"
/**
 * print_prompt - Prints the prompt to the standard output.
 * @prompt_str: Pointer to the string to be printed.
 * @length: Length of the prompt string.
 * Return: 0 if success or -1 if fails.
 */
int print_prompt(const char *prompt_str, unsigned int length)
{
	int chars_written;

	if (isatty(STDIN_FILENO))
	{
		chars_written = write(1, prompt_str, length);
		if (chars_written == -1)
			return (-1);
	}
	return (0);
}
