#include "holberton.h"
/**
 * duplicate_string - Duplicates a string.
 * @str: String to be duplicated.
 * Return: Pointer to the duplicated string or NULL if malloc fails.
 */
char *duplicate_string(char *str)
{
	unsigned int i, length;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
		;
	duplicate = (char *) malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
	{
		duplicate[i] = str[i];
	}
	return (duplicate);
}
