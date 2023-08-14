#include "holberton.h"
/**
 * concatenate_paths - Concatenates a directory path with a command.
 * @directory: The directory path to be appended with the command.
 * @command: The command to be concatenated with the directory path.
 * Return: Pointer to the concatenated path.
 */
char *concatenate_paths(char *directory, char *command)
{
	int i, j = 0, len_dir, len_cmd;
	char *result_path = NULL;

	if (directory == NULL || command == NULL)
		return (NULL);

	len_dir = _string_length(directory);
	len_cmd = _string_length(command);
	result_path = malloc(len_dir + len_cmd + 2);
	if (result_path == NULL)
		return (NULL);

	for (i = 0; directory[i] != '\0'; i++)
	{
		result_path[i] = directory[i];
	}

	if (directory[i - 1] != '/')
	{
		result_path[i] = '/';
		i++;
	}

	while (command[j] != '\0')
	{
		result_path[i + j] = command[j];
		j++;
	}

	result_path[i + j] = '\0';
	return (result_path);
}
