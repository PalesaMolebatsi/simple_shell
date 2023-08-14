#include "holberton.h"
/**
 * compare_strings - Compares two strings.
 * @string1: First string to be compared.
 * @string2: Second string to be compared.
 * Return: 0 if the strings are the same, > 0 if string1 is greater,
 * < 0 if string2 is greater.
 */
int compare_strings(char *string1, char *string2)
{
	int i;

	for (i = 0; string1[i] != '\0'; i++)
		;
	for (i = 0; string2[i] != '\0'; i++)
	{
		if (string1[i] != string2[i])
		{
			return (string1[i] - string2[i]);
		}
	}
	return (0);
}
