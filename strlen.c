#include "holberton.h"
/**
 * get_string_length - Computes the length of a string.
 * @str: String to be measured.
 * Return: The length of the string.
 */
int get_string_length(const char *str)
{
	int length = 0;


	if (str == NULL)
		return (0);


	while (str[length] != '\0')
		length++;
	return (length);
}
