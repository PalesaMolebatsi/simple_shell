#include "holberton.h"
/**
 * fetch_global_variable - Retrieve the value of a global variable from the environment.
 * @var_name: Name of the global variable to extract from the environment.
 * Return: Pointer to the content of the variable, or NULL if it fails.
 */
char *fetch_global_variable(char *var_name)
{
	int i = 0;
	const char delimiter[] = "=";
	char *env_entry, *env_entry_dup, *value_dup;

	if (var_name != NULL)
	{
		if (environ == NULL)
			return (NULL);
		env_entry_dup = _strdup(environ[i]);
		while (env_entry_dup != NULL)
		{
			env_entry = strtok(env_entry_dup, delimiter);
			if (_strcmp(env_entry, var_name) == 0)
			{
				env_entry = strtok(NULL, delimiter);
				value_dup = _strdup(env_entry);
				free(env_entry_dup);
				return (value_dup);
			}
			i++;
			free(env_entry_dup);
			env_entry_dup = _strdup(environ[i]);
		}
	}
	return (NULL);
}
