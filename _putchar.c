#include "holberton.h"

/**
 * print_character - writes the character c to stdout
 * @character: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_character(char character)
{
	return (write(1, &character, 1));
}
