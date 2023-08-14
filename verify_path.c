#include "holberton.h"
/**
 * check_path - Verify if the first command can be executed.
 * @args: Array of entries by the user.
 * Return: 0 if success, or -1 if the executable file doesn't exist.
 */
int check_path(char **args)
{
	char *global_path = NULL;
	char *global_dup = NULL;
	char *dir_path = NULL;
	char *command_path = NULL;
	char *test_paths[121];
	int exist_stat = -1, i = 0;


	global_path = get_env_variable("PATH");
	if (global_path == NULL)
		return (-1);


	global_dup = duplicate_string(global_path);
	if (global_dup == NULL)
	{
		free(global_path);
		return (-1);
	}


	dir_path = strtok(global_dup, ":");
	while (exist_stat == -1 && dir_path != NULL)
	{
		command_path = append_command(dir_path, args[0]);
		test_paths[i] = command_path;
		exist_stat = check_existence(test_paths[i]);
		dir_path = strtok(NULL, ":");
		i++;
	}
	i--;


	free(global_path);
	free(global_dup);
	free_grid(test_paths, i + 1);


	if (exist_stat == 0)
	{
		args[0] = test_paths[i];
		return (0);
	}
	else
	{
		free(test_paths[i]);
		return (-1);
	}
}
